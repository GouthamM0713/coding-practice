
print("=== ELECTRICITY BILL CALCULATOR ===")

units = float(input("Enter electricity units consumed: "))

if units <= 100:
    bill = units * 3
elif units <= 200:
    bill = (100 * 3) + ((units - 100) * 5)
elif units <= 300:
    bill = (100 * 3) + (100 * 5) + ((units - 200) * 7)
else:
    bill = (100 * 3) + (100 * 5) + (100 * 7) + ((units - 300) * 10)

print("\nUnits consumed:", units)
print("Estimated electricity bill: Rs.", bill)
