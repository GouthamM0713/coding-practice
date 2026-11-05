with open("sample.txt", "w") as file:
    file.write("Python Programming\n")
    file.write("Coding Practice\n")
    file.write("Day 20 Challenge\n")

with open("sample.txt", "r") as file:
    lines = file.readlines()

print("Total lines:", len(lines))