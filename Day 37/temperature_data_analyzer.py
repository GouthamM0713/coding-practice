
temperatures = []

for day in range(1, 8):
    temp = float(input(f"Enter temperature for day {day}: "))
    temperatures.append(temp)

average = sum(temperatures) / len(temperatures)
highest = max(temperatures)
lowest = min(temperatures)

print("\nWEEKLY TEMPERATURE REPORT")
print("Average:", round(average, 2), "°C")
print("Highest:", highest, "°C")
print("Lowest:", lowest, "°C")

print("Days above average:")

for index, temp in enumerate(temperatures, 1):
    if temp > average:
        print("Day", index, ":", temp, "°C")
