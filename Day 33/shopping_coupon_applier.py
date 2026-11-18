
print("=== SHOPPING COUPON SYSTEM ===")

amount = float(input("Enter shopping amount: "))
coupon = input("Enter coupon code: ").strip().upper()

if amount < 0:
    print("Invalid shopping amount.")
else:
    discount = 0

    if coupon == "SAVE10" and amount >= 500:
        discount = 10
    elif coupon == "SAVE20" and amount >= 1000:
        discount = 20
    elif coupon == "SAVE30" and amount >= 2000:
        discount = 30
    else:
        print("Invalid coupon or minimum purchase not reached.")

    discount_amount = amount * discount / 100
    final_amount = amount - discount_amount

    print("\n=== BILL DETAILS ===")
    print("Original Amount: Rs.", amount)
    print("Discount:", discount, "%")
    print("Discount Amount: Rs.", round(discount_amount, 2))
    print("Final Amount: Rs.", round(final_amount, 2))
