def read_matrix(rows, cols, name):
    matrix = []

    print(f"\nEnter values for {name}:")

    for i in range(rows):
        while True:
            try:
                values = list(map(
                    int,
                    input(f"Row {i + 1}: ").split()
                ))

                if len(values) != cols:
                    print(f"Enter exactly {cols} numbers!")
                    continue

                matrix.append(values)
                break

            except ValueError:
                print("Enter integers only!")

    return matrix


r1 = int(input("Rows in first matrix: "))
c1 = int(input("Columns in first matrix: "))

r2 = int(input("Rows in second matrix: "))
c2 = int(input("Columns in second matrix: "))

if min(r1, c1, r2, c2) <= 0:
    print("Dimensions must be positive!")
elif c1 != r2:
    print("Matrix multiplication is not possible!")
else:
    A = read_matrix(r1, c1, "Matrix A")
    B = read_matrix(r2, c2, "Matrix B")

    result = [
        [0 for _ in range(c2)]
        for _ in range(r1)
    ]

    for i in range(r1):
        for j in range(c2):
            for k in range(c1):
                result[i][j] += A[i][k] * B[k][j]

    print("\nResult:")

    for row in result:
        print(*row)