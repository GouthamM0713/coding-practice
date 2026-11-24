def tower_of_hanoi(n, source, auxiliary, destination):
    if n == 1:
        print(f"Move disk 1 from {source} to {destination}")
        return

    tower_of_hanoi(n - 1, source, destination, auxiliary)

    print(f"Move disk {n} from {source} to {destination}")

    tower_of_hanoi(n - 1, auxiliary, source, destination)


disks = int(input("Enter number of disks: "))

if disks <= 0:
    print("Enter a positive number.")
else:
    print("\nSteps:")

    tower_of_hanoi(disks, "A", "B", "C")

    print("Total moves:", 2 ** disks - 1)