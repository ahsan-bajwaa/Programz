import os
import cv2
import pickle
import face_recognition
import numpy as np
from datetime import datetime, timedelta
from collections import deque, defaultdict
import csv
import time

# Constants
ENCODINGS_DIR = "face_encodings"
LOG_FILE = "face_logs.csv"
TARGET_WIDTH = 840
TARGET_HEIGHT = 580
FRAME_SKIP = 6
FACE_DISTANCE_THRESHOLD = 0.5
MIN_ENCODINGS_TO_SAVE = 5
MAX_ENCODINGS_PER_USER = 20
BOX_DISPLAY_DURATION = 1.0  # seconds to keep the box visible
ENTRY_COOLDOWN = timedelta(seconds=3)  # 3 seconds between logs
PRESENCE_THRESHOLD = timedelta(seconds=5)  # Considered "exited" after 5 seconds absent

# Track user presence and last log times
user_presence = defaultdict(lambda: {'last_seen': None, 'last_logged': None, 'status': 'exited'})

def initialize_log_file():
    """Ensure log file exists with proper headers"""
    if not os.path.exists(LOG_FILE):
        with open(LOG_FILE, mode="w", newline="") as f:
            writer = csv.writer(f)
            writer.writerow(["Timestamp", "Username", "Status", "Confidence", "Duration"])

def log_face_event(username, status, confidence, duration=None):
    """Log face events with cooldown and entry/exit tracking"""
    timestamp = datetime.now()
    
    # Skip if we recently logged this user with same status
    if (user_presence[username]['last_logged'] and 
        (timestamp - user_presence[username]['last_logged']) < ENTRY_COOLDOWN and
        user_presence[username]['status'] == status):
        return
    
    # Calculate duration for exit events
    if status == "exited" and user_presence[username]['last_seen']:
        duration = (timestamp - user_presence[username]['last_seen']).total_seconds()
    
    with open(LOG_FILE, mode="a", newline="") as f:
        writer = csv.writer(f)
        writer.writerow([
            timestamp.strftime("%Y-%m-%d %H:%M:%S"),
            username,
            status,
            f"{confidence:.3f}",
            f"{duration:.1f}s" if duration else ""
        ])
    
    # Update tracking
    user_presence[username]['last_logged'] = timestamp
    user_presence[username]['status'] = status
    if status == "entered":
        user_presence[username]['last_seen'] = timestamp
        
def capture_and_save_face(username):
    """Capture face images and save encodings for a new user"""
    ip_address = "http://Aaa:98760@192.168.193.182:7788/video"
    cap = cv2.VideoCapture(ip_address)
    
    if not cap.isOpened():
        print(f"[ERROR] Couldn't open stream at {ip_address}")
        return

    # Set camera resolution first
    cap.set(cv2.CAP_PROP_FRAME_WIDTH, TARGET_WIDTH)
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, TARGET_HEIGHT)
    
    encodings = deque(maxlen=MAX_ENCODINGS_PER_USER)
    frame_count = 0
    last_box_time = 0
    box_coordinates = None
    
    # Load existing encodings if they exist
    file_path = os.path.join(ENCODINGS_DIR, f"{username}.pkl")
    if os.path.exists(file_path):
        with open(file_path, 'rb') as f:
            existing_encodings = pickle.load(f)
            encodings.extend(existing_encodings[-MAX_ENCODINGS_PER_USER//2:])
        print(f"[INFO] Loaded {len(existing_encodings)} existing encodings for '{username}'")

    print("[INFO] Capturing face encodings. Press 'q' to stop.")
    
    # Create a resizable window
    cv2.namedWindow("Register Face", cv2.WINDOW_NORMAL)
    
    while True:
        ret, frame = cap.read()
        if not ret:
            print("[ERROR] Failed to read frame from camera.")
            break
        
        frame_count += 1
        current_time = time.time()
        
        # Process every frame but only analyze some frames
        processed_frame = frame.copy()
        
        # Only do face detection on some frames
        if frame_count % FRAME_SKIP == 0:
            # Resize frame for processing (not display)
            rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            rgb = cv2.resize(rgb, (0, 0), fx=0.5, fy=0.5)  # Process at half resolution
            
            # Use HOG model for faster detection
            boxes = face_recognition.face_locations(rgb, model="hog")
            
            # Scale boxes back to original size
            boxes = [(top*2, right*2, bottom*2, left*2) for (top, right, bottom, left) in boxes]
            
            # Only process if exactly one face is detected
            if len(boxes) == 1:
                new_encs = face_recognition.face_encodings(rgb, [(top//2, right//2, bottom//2, left//2) for (top, right, bottom, left) in boxes])
                
                for (top, right, bottom, left), enc in zip(boxes, new_encs):
                    # Check if this encoding is significantly different from previous ones
                    if len(encodings) > 0:
                        matches = face_recognition.compare_faces(list(encodings), enc, tolerance=0.5)
                        if not any(matches):
                            print("[INFO] New facial variation detected - adding to encodings")
                            encodings.append(enc)
                        else:
                            # Still add occasionally to reinforce memory of user
                            if frame_count % 10 == 0:
                                encodings.append(enc)
                    else:
                        encodings.append(enc)
                    
                    # Update box coordinates and timestamp
                    box_coordinates = ((top, right, bottom, left), username)
                    last_box_time = current_time
        
        # Display the box if within the display duration
        if box_coordinates and (current_time - last_box_time) < BOX_DISPLAY_DURATION:
            (top, right, bottom, left), name = box_coordinates
            cv2.rectangle(processed_frame, (left, top), (right, bottom), (0, 255, 0), 2)
            cv2.putText(processed_frame, name, (left, top - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 1)
            cv2.putText(processed_frame, f"Encodings: {len(encodings)}/{MAX_ENCODINGS_PER_USER}", 
                       (10, 20), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 1)
        
        # Scale down the display frame if needed
        display_scale = 0.7  # Adjust this value to make window smaller (0.5 = half size)
        if display_scale != 1.0:
            processed_frame = cv2.resize(processed_frame, (0, 0), fx=display_scale, fy=display_scale)
        
        cv2.imshow("Register Face", processed_frame)
        
        # Allow window to be resized by user
        if cv2.getWindowProperty("Register Face", cv2.WND_PROP_VISIBLE) < 1:
            break
            
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows()

    if len(encodings) >= MIN_ENCODINGS_TO_SAVE:
        with open(file_path, 'wb') as f:
            pickle.dump(list(encodings), f)
        print(f"[INFO] Saved {len(encodings)} encodings for '{username}'")
    else:
        print(f"[ERROR] Not enough quality encodings captured (minimum {MIN_ENCODINGS_TO_SAVE} required).")        
        

def verify_user_face():
    """Verify faces with improved logging system"""
    initialize_log_file()
    ip_address = "http://Aaa:98760@192.168.193.182:7788/video"
    
    # Load known users
    try:
        known_users = [f[:-4] for f in os.listdir(ENCODINGS_DIR) if f.endswith(".pkl")]
        if not known_users:
            print("[ERROR] No users found. Please register first.")
            return

        known_data = {}
        for user in known_users:
            with open(os.path.join(ENCODINGS_DIR, f"{user}.pkl"), 'rb') as f:
                known_data[user] = pickle.load(f)
    except Exception as e:
        print(f"[ERROR] Failed to load user data: {str(e)}")
        return

    cap = cv2.VideoCapture(ip_address)
    if not cap.isOpened():
        print(f"[ERROR] Couldn't open stream at {ip_address}")
        return

    # Set camera properties
    cap.set(cv2.CAP_PROP_FPS, 15)
    cap.set(cv2.CAP_PROP_FRAME_WIDTH, TARGET_WIDTH)
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, TARGET_HEIGHT)

    frame_count = 0
    current_detections = set()
    processing = False
    last_boxes = {}
    print("[INFO] Verifying faces. Press 'q' to stop.")
    cv2.namedWindow("Verification", cv2.WINDOW_NORMAL)

    while True:
        ret, frame = cap.read()
        if not ret:
            print("[ERROR] Failed to grab frame.")
            break

        frame = cv2.resize(frame, (TARGET_WIDTH, TARGET_HEIGHT))
        frame_count += 1
        display_frame = frame.copy()
        current_time = time.time()
        
        # Process every frame but only analyze some frames
        if frame_count % (FRAME_SKIP + 1) == 0:
            processing = True
            current_detections.clear()
            
            # Process smaller frame for better performance
            small_frame = cv2.resize(frame, (0, 0), fx=0.5, fy=0.5)
            rgb_small = cv2.cvtColor(small_frame, cv2.COLOR_BGR2RGB)
            boxes = face_recognition.face_locations(rgb_small, model="hog")
            encodings = face_recognition.face_encodings(rgb_small, boxes)

            # Scale back up the boxes coordinates to full size
            boxes = [(top*2, right*2, bottom*2, left*2) for (top, right, bottom, left) in boxes]
            
            for (top, right, bottom, left), face_enc in zip(boxes, encodings):
                best_match = ("Unknown", 1.0)
                for name, known_encs in known_data.items():
                    distances = face_recognition.face_distance(known_encs, face_enc)
                    min_dist = np.min(distances) if len(distances) > 0 else 1.0
                    if min_dist < best_match[1]:
                        best_match = (name, min_dist)

                name, distance = best_match
                color = (0, 255, 0) if distance < FACE_DISTANCE_THRESHOLD else (0, 0, 255)
                
                if distance < FACE_DISTANCE_THRESHOLD:
                    current_detections.add(name)
                    now = datetime.now()
                    
                    # Log entry if this is a new appearance or return after absence
                    if (user_presence[name]['status'] == "exited" or 
                        (user_presence[name]['last_seen'] and 
                         (now - user_presence[name]['last_seen']) > PRESENCE_THRESHOLD)):
                        log_face_event(name, "entered", distance)
                    
                    user_presence[name]['last_seen'] = now
                
                # Store this face position
                last_boxes[name] = {
                    'coords': (top, right, bottom, left),
                    'color': color,
                    'distance': distance,
                    'time': current_time
                }
            
            processing = False
        
        # Check for exits (users no longer detected)
        for name in list(user_presence.keys()):
            if (name not in current_detections and 
                name in user_presence and 
                user_presence[name]['last_seen'] and 
                (datetime.now() - user_presence[name]['last_seen']) > PRESENCE_THRESHOLD and
                user_presence[name]['status'] == "entered"):
                log_face_event(name, "exited", user_presence[name].get('last_confidence', 0))
        
        # Draw all stored face boxes
        for name, box_data in last_boxes.items():
            if current_time - box_data['time'] < 1.0:  # Only show recent detections
                top, right, bottom, left = box_data['coords']
                color = box_data['color']
                distance = box_data['distance']
                
                cv2.rectangle(display_frame, (left, top), (right, bottom), color, 2)
                status = user_presence.get(name, {}).get('status', 'unknown')
                cv2.putText(display_frame, f"{name} ({status}, {distance:.2f})", 
                            (left + 6, bottom - 6), cv2.FONT_HERSHEY_SIMPLEX, 0.7, color, 2)
        
        # Show processing indicator if needed
        if processing:
            cv2.putText(display_frame, "Processing...", (10, 30),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)
        
        # Scale down for display if needed
        display_scale = 0.7
        if display_scale != 1.0:
            display_frame = cv2.resize(display_frame, (0, 0), fx=display_scale, fy=display_scale)
        
        cv2.imshow("Verification", display_frame)
        
        if cv2.getWindowProperty("Verification", cv2.WND_PROP_VISIBLE) < 1 or cv2.waitKey(1) & 0xFF == ord('q'):
            break

    # Log exits for all remaining users when closing
    for name in list(user_presence.keys()):
        if user_presence[name]['status'] == "entered":
            log_face_event(name, "exited", user_presence[name].get('last_confidence', 0))
    
    cap.release()
    cv2.destroyAllWindows()
    
def list_users():
    """List all registered users"""
    try:
        users = [f[:-4] for f in os.listdir(ENCODINGS_DIR) if f.endswith(".pkl")]
        print("\n[INFO] Registered Users:")
        for i, user in enumerate(users, 1):
            print(f"{i}. {user}")
        print(f"\nTotal: {len(users)} users")
    except Exception as e:
        print(f"[ERROR] Failed to list users: {str(e)}")

def delete_user(username):
    """Delete a user's face data"""
    try:
        path = os.path.join(ENCODINGS_DIR, f"{username}.pkl")
        if os.path.exists(path):
            os.remove(path)
            print(f"[INFO] Deleted face data for '{username}'.")
        else:
            print(f"[ERROR] No encoding found for '{username}'.")
    except Exception as e:
        print(f"[ERROR] Failed to delete user: {str(e)}")

def view_logs():
    """Display verification logs"""
    try:
        if not os.path.exists(LOG_FILE):
            print("[INFO] No logs found.")
            return
        
        print("\n[INFO] Verification Logs:")
        with open(LOG_FILE, newline='') as f:
            reader = csv.reader(f)
            for i, row in enumerate(reader, 1):
                print(f"{i}. {row[0]} | {row[1]:<10} | {row[2]:<6} | {row[3]}")
    except Exception as e:
        print(f"[ERROR] Failed to read logs: {str(e)}")

def main():
    """Main menu interface"""
    while True:
        print("\n==== FACE RECOGNITION SYSTEM ====")
        print("1. Register a new user")
        print("2. Verify a face")
        print("3. List registered users")
        print("4. Delete a user")
        print("5. View verification logs")
        print("6. Exit")
        
        try:
            choice = input("Choose an option (1-6): ").strip()
            
            if choice == '1':
                username = input("Enter username: ").strip().lower()
                if username:
                    capture_and_save_face(username)
                else:
                    print("[ERROR] Username cannot be empty")
            elif choice == '2':
                verify_user_face()
            elif choice == '3':
                list_users()
            elif choice == '4':
                username = input("Enter username to delete: ").strip().lower()
                delete_user(username)
            elif choice == '5':
                view_logs()
            elif choice == '6':
                print("Goodbye!")
                break
            else:
                print("[ERROR] Invalid choice. Please enter 1-6")
        except KeyboardInterrupt:
            print("\n[INFO] Operation cancelled by user")
        except Exception as e:
            print(f"[ERROR] An error occurred: {str(e)}")

if __name__ == "__main__":
    main()    
