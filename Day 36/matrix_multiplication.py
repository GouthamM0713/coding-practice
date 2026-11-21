
rows_a = int(input("Rows of first matrix: "))
cols_a = int(input("Columns of first matrix: "))

rows_b = int(input("Rows of second matrix: "))
cols_b = int(input("Columns of second matrix: "))

if rows_a <= 0 or cols_a <= 0 or rows_b <= 0 or cols_b <= 0:
    print("Dimensions must be positive")
elif cols_a != rows_b:
    print("Matrix multiplication is not possible")
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

    result = [[0] * cols_b for _ in range(rows_a)]

    for i in range(rows_a):
        for j in range(cols_b):
            for k in range(cols_a):
                result[i][j] += a[i][k] * b[k][j]

    print("Product matrix:")
    for row in result:
        print(row)
