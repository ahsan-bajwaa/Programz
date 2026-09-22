current_location = "A"
goal = "D"

path = ["A", "B", "C", "D"]


for location in path:

    current_location = location

    print("Agent is at:", current_location)

    if current_location == goal:
        print("Goal reached!")
        break