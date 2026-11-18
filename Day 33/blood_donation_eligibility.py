
print("=== BLOOD DONATION ELIGIBILITY CHECKER ===")

age = int(input("Enter your age: "))
weight = float(input("Enter your weight in kg: "))

if age >= 18 and age <= 65 and weight >= 50:
    print("\nYou may be eligible to donate blood.")
else:
    print("\nYou may not meet the basic age or weight criteria.")

print("Please consult a qualified medical professional before donating.")
