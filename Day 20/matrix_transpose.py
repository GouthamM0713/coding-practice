matrix = [
    [1, 2, 3],
    [4, 5, 6]
]

transpose = []

for i in range(len(matrix[0])):
    row = []
    for j in range(len(matrix)):
        row.append(matrix[j][i])
    transpose.append(row)

print("Transpose:")
for row in transpose:
    print(row)