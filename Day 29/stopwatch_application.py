import time

start_time = None
elapsed = 0

while True:
    print("\n1. Start")
    print("2. Stop")
    print("3. Reset")
    print("4. Exit")

    choice = input("Choose: ")

    if choice == "1":
        if start_time is None:
            start_time = time.perf_counter()
            print("Stopwatch started!")
        else:
            print("Already running!")

    elif choice == "2":
        if start_time is not None:
            elapsed += time.perf_counter() - start_time
            start_time = None
            print("Elapsed:", round(elapsed, 2), "seconds")
        else:
            print("Stopwatch is not running!")

    elif choice == "3":
        start_time = None
        elapsed = 0
        print("Stopwatch reset!")

    elif choice == "4":
        break

    else:
        print("Invalid choice!")

if start_time is not None:
    elapsed += time.perf_counter() - start_time

print("Final time:", round(elapsed, 2), "seconds")