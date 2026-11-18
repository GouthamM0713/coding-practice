
print("=== GYM MEMBERSHIP MANAGER ===")

name = input("Enter member name: ")
months = int(input("Enter membership duration in months: "))

monthly_fee = 800
discount = 0

if months >= 12:
    discount = 0.20
elif months >= 6:
    discount = 0.10

total = months * monthly_fee
discount_amount = total * discount
final_amount = total - discount_amount

print("\n=== MEMBERSHIP DETAILS ===")
print("Member:", name)
print("Duration:", months, "months")
print("Original Fee: Rs.", total)
print("Discount: Rs.", discount_amount)
print("Final Fee: Rs.", final_amount)
