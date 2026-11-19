
distance = float(input("Enter distance travelled in km: "))
fuel = float(input("Enter fuel consumed in litres: "))

if distance < 0 or fuel <= 0:
    print("Invalid input")
else:
    mileage = distance / fuel

    print("Vehicle mileage:", round(mileage, 2), "km/l")

    if mileage >= 20:
        print("Excellent fuel efficiency!")
    elif mileage >= 15:
        print("Good fuel efficiency!")
    else:
        print("Fuel efficiency needs improvement.")
