class Employee:

    def __init__(self, name, basic_salary):
        self.name = name
        self.basic_salary = basic_salary

    def calculate_salary(self):
        hra = self.basic_salary * 0.20
        da = self.basic_salary * 0.10
        pf = self.basic_salary * 0.12

        gross = self.basic_salary + hra + da
        net = gross - pf

        return hra, da, pf, gross, net


try:
    name = input("Enter employee name: ").strip()
    salary = float(input("Enter basic salary: "))

    if not name or salary <= 0:
        print("Enter a valid name and positive salary.")
    else:
        employee = Employee(name, salary)

        hra, da, pf, gross, net = employee.calculate_salary()

        print("\nEMPLOYEE PAYSLIP")
        print("Name:", employee.name)
        print("Basic Salary:", salary)
        print("HRA:", hra)
        print("DA:", da)
        print("PF:", pf)
        print("Gross Salary:", gross)
        print("Net Salary:", net)

except ValueError:
    print("Enter a valid salary!")