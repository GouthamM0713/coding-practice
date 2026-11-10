print("Welcome to the Mystery Forest!")
print("You are standing in front of two paths.")

print("\n1. Enter the dark cave")
print("2. Walk towards the river")

choice = input("Choose your path (1/2): ")

if choice == "1":
    print("\nYou entered a mysterious cave.")
    print("You found a treasure chest!")

    action = input("Open the chest? (yes/no): ").lower()

    if action == "yes":
        print("Congratulations! You found gold!")
    else:
        print("You left the treasure behind.")

elif choice == "2":
    print("\nYou reached a river.")
    print("You found a small boat.")

    action = input("Do you want to cross? (yes/no): ").lower()

    if action == "yes":
        print("You successfully crossed the river!")
        print("You discovered a hidden village.")
    else:
        print("You returned safely.")

else:
    print("Invalid choice. Game over!")

print("\nThanks for playing!")