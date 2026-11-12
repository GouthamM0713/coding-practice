import csv
from collections import defaultdict

filename = "sales.csv"
sales = defaultdict(float)
total_revenue = 0

try:
    with open(filename, "r", newline="") as file:
        reader = csv.DictReader(file)

        for row in reader:
            product = row["Product"]
            quantity = int(row["Quantity"])
            price = float(row["Price"])

            revenue = quantity * price
            sales[product] += revenue
            total_revenue += revenue

    print("\n----- SALES REPORT -----")

    for product, amount in sales.items():
        print(f"{product}: ₹{amount:.2f}")

    print("------------------------")
    print(f"Total Revenue: ₹{total_revenue:.2f}")

except FileNotFoundError:
    print("sales.csv file not found!")

except (ValueError, KeyError):
    print("Invalid CSV data or column names!")