import csv

filename = input("Enter weather CSV filename: ")

temperatures = []

try:
    with open(filename, "r", newline="") as file:
        reader = csv.DictReader(file)

        for row in reader:
            try:
                temperatures.append(float(row["temperature"]))
            except (ValueError, KeyError):
                continue

    if temperatures:
        average = sum(temperatures) / len(temperatures)

        print("\n--- Weather Report ---")
        print("Records:", len(temperatures))
        print(f"Average Temperature: {average:.2f}°C")
        print(f"Highest Temperature: {max(temperatures):.2f}°C")
        print(f"Lowest Temperature: {min(temperatures):.2f}°C")

    else:
        print("No valid temperature data found!")

except FileNotFoundError:
    print("CSV file not found!")

except Exception as error:
    print("Error:", error)