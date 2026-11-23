principal = float(input("Enter principal amount: "))
rate1 = float(input("Enter first interest rate: "))
rate2 = float(input("Enter second interest rate: "))
time = float(input("Enter time in years: "))

interest1 = (principal * rate1 * time) / 100
interest2 = (principal * rate2 * time) / 100

print("\nInterest Comparison")
print("First option:", interest1)
print("Second option:", interest2)

if interest1 > interest2:
    print("First option gives more interest.")
elif interest2 > interest1:
    print("Second option gives more interest.")
else:
    print("Both options give equal interest.")