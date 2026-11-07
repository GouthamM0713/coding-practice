from datetime import date

date1 = date.fromisoformat(
    input("Enter first date (YYYY-MM-DD): ")
)

date2 = date.fromisoformat(
    input("Enter second date (YYYY-MM-DD): ")
)

difference = abs((date2 - date1).days)

years = difference // 365
months = (difference % 365) // 30
days = (difference % 365) % 30

print("\nDate Difference")
print("Total days:", difference)
print("Approximate years:", years)
print("Approximate months:", months)
print("Remaining days:", days)