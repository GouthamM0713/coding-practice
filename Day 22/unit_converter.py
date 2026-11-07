print("UNIT CONVERTER")
print("1. Kilometers to Miles")
print("2. Miles to Kilometers")
print("3. Celsius to Fahrenheit")
print("4. Fahrenheit to Celsius")
print("5. Kilograms to Pounds")
print("6. Pounds to Kilograms")

choice = int(input("Enter choice: "))
value = float(input("Enter value: "))

if choice == 1:
    print("Miles:", value * 0.621371)

elif choice == 2:
    print("Kilometers:", value / 0.621371)

elif choice == 3:
    print("Fahrenheit:", (value * 9 / 5) + 32)

elif choice == 4:
    print("Celsius:", (value - 32) * 5 / 9)

elif choice == 5:
    print("Pounds:", value * 2.20462)

elif choice == 6:
    print("Kilograms:", value / 2.20462)

else:
    print("Invalid choice!")