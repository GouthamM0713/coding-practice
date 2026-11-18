
print("=== EVENT SEAT ALLOCATOR ===")

total_seats = 20
booked_seats = set()

while True:
    print("\nAvailable seats:", total_seats - len(booked_seats))
    print("Booked seats:", sorted(booked_seats))

    choice = input("Enter seat number (1-20) or 'exit': ").strip().lower()

    if choice == "exit":
        break

    if not choice.isdigit():
        print("Please enter a valid seat number.")
        continue

    seat = int(choice)

    if seat < 1 or seat > total_seats:
        print("Invalid seat number!")
    elif seat in booked_seats:
        print("Seat already booked!")
    else:
        booked_seats.add(seat)
        print("Seat", seat, "booked successfully!")

print("\nTotal booked seats:", len(booked_seats))
print("Total available seats:", total_seats - len(booked_seats))
