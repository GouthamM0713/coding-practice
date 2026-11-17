def determinant(matrix):
    n = len(matrix)

    if n == 1:
        return matrix[0][0]

    if n == 2:
        return (
            matrix[0][0] * matrix[1][1]
            - matrix[0][1] * matrix[1][0]
        )

    result = 0

    for col in range(n):
        minor = [
            row[:col] + row[col + 1:]
            for row in matrix[1:]
        ]

        sign = (-1) ** col

        result += (
            sign
            * matrix[0][col]
            * determinant(minor)
        )

    return result


n = int(input("Enter matrix order: "))

if n <= 0:
    print("Order must be positive!")

else:
    matrix = []

    print("Enter matrix elements row by row:")

    for i in range(n):
        row = list(map(
            int,
            input(f"Row {i + 1}: ").split()
        ))

        if len(row) != n:
            print("Each row must contain", n, "elements!")
            break

        matrix.append(row)

    if len(matrix) == n:
        print("\nDeterminant:", determinant(matrix))