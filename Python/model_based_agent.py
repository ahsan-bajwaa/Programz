rooms = {
    "Room 1": "dirty",
    "Room 2": "clean",
    "Room 3": "dirty"
}


def model_based_agent(room_name):

    for room, status in rooms.items():
        if room == room_name:
            print(room, "status:", status)
            break

    if status == "dirty":
        print(room_name, "is dirty.")
        print("Action: Clean the room.")

        # Update internal model after cleaning
        rooms[room_name] = "clean"

    else:
        print(room_name, "is already clean.")
        print("Action: Move to another room.")


print("Initial room model:")
print(rooms)

print()

model_based_agent("Room 3")

print()

print("Updated room model:")
print(rooms)