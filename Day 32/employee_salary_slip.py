name = input("Enter employee name: ")
employee_id = input("Enter employee ID: ")

basic = float(input("Enter basic salary: "))
hra = float(input("Enter HRA: "))
allowance = float(input("Enter other allowances: "))
deduction = float(input("Enter deductions: "))

gross = basic + hra + allowance
net = gross - deduction

print("\n========== SALARY SLIP ==========")

print("Employee Name:", name)
print("Employee ID:", employee_id)

print("---------------------------------")
print(f"Basic Salary: ₹{basic:.2f}")
print(f"HRA: ₹{hra:.2f}")
print(f"Other Allowances: ₹{allowance:.2f}")

print("---------------------------------")
print(f"Gross Salary: ₹{gross:.2f}")
print(f"Total Deductions: ₹{deduction:.2f}")

print("---------------------------------")
print(f"Net Salary: ₹{net:.2f}")
print("=================================")