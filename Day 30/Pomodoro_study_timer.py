import time

def countdown(minutes, label):
    total_seconds = minutes * 60

    print(f"\n{label} started!")

    while total_seconds > 0:
        mins, secs = divmod(total_seconds, 60)

        print(
            f"\rTime remaining: {mins:02d}:{secs:02d}",
            end="",
            flush=True
        )

        time.sleep(1)
        total_seconds -= 1

    print(f"\r{label} completed!          ")


study_minutes = int(input("Study duration in minutes: "))
break_minutes = int(input("Break duration in minutes: "))

if study_minutes <= 0 or break_minutes <= 0:
    print("Durations must be positive!")
else:
    session = 1

    while True:
        countdown(study_minutes, f"Study session {session}")

        choice = input("\nTake a break? (yes/no): ").lower()

        if choice != "yes":
            break

        countdown(break_minutes, "Break")

        session += 1

    print("\nGreat work! Keep learning!")