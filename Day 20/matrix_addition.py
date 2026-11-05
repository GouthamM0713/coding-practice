a = [
    [1, 2],
    [3, 4]
]

b = [
    [5, 6],
    [7, 8]
]

result = []

for i in range(len(a)):
    row = []
    for j in range(len(a[0])):
        row.append(a[i][j] + b[i][j])
    result.append(row)

print("Sum of matrices:")

for row in result:
    print(row)