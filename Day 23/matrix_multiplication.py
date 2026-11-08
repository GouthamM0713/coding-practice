rows_a = int(input("Rows of first matrix: "))
cols_a = int(input("Columns of first matrix: "))

rows_b = int(input("Rows of second matrix: "))
cols_b = int(input("Columns of second matrix: "))

if cols_a != rows_b:
    print("Matrix multiplication is not possible.")
else:
    print("Enter first matrix:")

    a = [
        [int(input(f"A[{i}][{j}]: ")) for j in range(cols_a)]
        for i in range(rows_a)
    ]

    print("Enter second matrix:")

    b = [
        [int(input(f"B[{i}][{j}]: ")) for j in range(cols_b)]
        for i in range(rows_b)
    ]

    result = [
        [0 for _ in range(cols_b)]
        for _ in range(rows_a)
    ]

    for i in range(rows_a):
        for j in range(cols_b):
            for k in range(cols_a):
                result[i][j] += a[i][k] * b[k][j]

    print("\nProduct matrix:")

    for row in result:
        print(row)