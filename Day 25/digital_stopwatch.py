import time

print("Digital Stopwatch")

input("Press ENTER to start...")
start_time = time.time()

input("Press ENTER to stop...")

end_time = time.time()

elapsed = end_time - start_time

hours = int(elapsed // 3600)
minutes = int((elapsed % 3600) // 60)
seconds = elapsed % 60

print("\nStopwatch Result")
print("----------------")
print(f"Hours: {hours}")
print(f"Minutes: {minutes}")
print(f"Seconds: {seconds:.2f}")

print(f"Total time: {elapsed:.2f} seconds")