
capacity = float(input("Enter tank capacity in litres: "))
current = float(input("Enter current water level in litres: "))
flow = float(input("Enter water flow rate (litres/min): "))

if capacity <= 0 or current < 0 or current > capacity or flow <= 0:
    print("Invalid input")
else:
    remaining = capacity - current
    time = remaining / flow

    print("Remaining water required:", remaining, "litres")
    print("Filling time:", round(time, 2), "minutes")
