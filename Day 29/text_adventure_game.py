def start_game():
    print("\nWelcome to Treasure Island!")
    print("Your mission is to find the hidden treasure.")

    choice = input(
        "\nYou reach a forest. Go LEFT or RIGHT? "
    ).lower()

    if choice == "left":
        print("\nYou find a river.")

        choice = input(
            "Do you SWIM or WAIT for a boat? "
        ).lower()

        if choice == "wait":
            print("\nA boat takes you to an island.")

            choice = input(
                "Choose a door: RED, BLUE or YELLOW: "
            ).lower()

            if choice == "yellow":
                print("\nCongratulations! You found the treasure!")
            elif choice == "red":
                print("\nThe room is full of fire. Game over!")
            elif choice == "blue":
                print("\nA wild animal appears. Game over!")
            else:
                print("\nInvalid door. Game over!")

        elif choice == "swim":
            print("\nA crocodile attacks you. Game over!")

        else:
            print("\nInvalid choice. Game over!")

    elif choice == "right":
        print("\nYou fall into a hidden trap. Game over!")

    else:
        print("\nInvalid direction. Game over!")


while True:
    start_game()

    again = input("\nPlay again? (yes/no): ").lower()

    if again != "yes":
        print("Thanks for playing!")
        break