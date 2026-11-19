
goal = int(input("Enter your reading goal (pages): "))
pages = int(input("Enter pages already read: "))

if goal <= 0 or pages < 0:
    print("Invalid input")
else:
    remaining = max(0, goal - pages)
    percentage = min(100, (pages / goal) * 100)

    print("Reading progress:", round(percentage, 2), "%")
    print("Pages remaining:", remaining)

    if remaining == 0:
        print("Congratulations! Goal completed!")
    else:
        print("Keep reading!")
