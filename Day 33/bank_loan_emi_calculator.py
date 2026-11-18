
print("=== BANK LOAN EMI CALCULATOR ===")

principal = float(input("Enter loan amount: "))
annual_rate = float(input("Enter annual interest rate (%): "))
years = int(input("Enter loan duration in years: "))

if principal <= 0 or annual_rate < 0 or years <= 0:
    print("Please enter valid loan details.")
else:
    months = years * 12
    monthly_rate = annual_rate / (12 * 100)

    if monthly_rate == 0:
        emi = principal / months
    else:
        factor = (1 + monthly_rate) ** months
        emi = principal * monthly_rate * factor / (factor - 1)

    total_payment = emi * months
    total_interest = total_payment - principal

    print("\n=== LOAN DETAILS ===")
    print("Monthly EMI: Rs.", round(emi, 2))
    print("Total Payment: Rs.", round(total_payment, 2))
    print("Total Interest: Rs.", round(total_interest, 2))
