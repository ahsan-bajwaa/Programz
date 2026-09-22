def simple_reflex_agent(room_status):
    room_status = room_status.lower()

    if room_status == "dirty":
        return "Clean the room"
    else:
        return "Move to the next room"


status = input("Enter room status (clean/dirty): ")

action = simple_reflex_agent(status)

print("Agent action:", action)