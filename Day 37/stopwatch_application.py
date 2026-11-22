
import time

input("Press Enter to start stopwatch...")
start = time.perf_counter()

input("Press Enter to stop stopwatch...")
end = time.perf_counter()

elapsed = end - start

minutes = int(elapsed // 60)
seconds = elapsed % 60

print("\nSTOPWATCH RESULT")
print("Minutes:", minutes)
print("Seconds:", round(seconds, 2))
print("Total time:", round(elapsed, 2), "seconds")
