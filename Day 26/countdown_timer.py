import time

try:
    seconds = int(input("Enter countdown time in seconds: "))

    if seconds <= 0:
        print("Enter a positive number.")

    else:
        print("\nCountdown started!")

        while seconds > 0:
            minutes, remaining = divmod(seconds, 60)

            print(
                f"\rTime remaining: {minutes:02d}:{remaining:02d}",
                end="",
                flush=True
            )

            time.sleep(1)
            seconds -= 1

        print("\rTime remaining: 00:00")
        print("Time is up!")

except ValueError:
    print("Please enter a valid integer!")