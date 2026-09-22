# Simple reflex agent for a vacuum cleaner world
def vacuum_agent(room_status):
    room_status = room_status.lower()

    if room_status == "dirty": 
        return "Action: clean the room.."
    else:
        return "Action: move to next room.."

status = input("Enter the status of the room (clean/dirty): ")
print(vacuum_agent(status))

# Model based vacuum cleaner agent:
rooms = {
    "Room 1": "dirty",
    "Room 2": "clean",
    "Room 3": "dirty"
}