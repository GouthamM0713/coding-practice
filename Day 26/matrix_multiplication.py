try:
    r1 = int(input("Enter rows of first matrix: "))
    c1 = int(input("Enter columns of first matrix: "))

    r2 = int(input("Enter rows of second matrix: "))
    c2 = int(input("Enter columns of second matrix: "))

    if min(r1, c1, r2, c2) <= 0:
        print("Dimensions must be positive.")

    elif c1 != r2:
        print("Matrix multiplication is not possible.")

    else:
        print("Enter first matrix:")

        A = [
            list(map(int, input().split()))
            for _ in range(r1)
        ]

        print("Enter second matrix:")

        B = [
            list(map(int, input().split()))
            for _ in range(r2)
        ]

        if any(len(row) != c1 for row in A) or any(
            len(row) != c2 for row in B
        ):
            print("Invalid matrix dimensions.")

        else:
            result = [
                [
                    sum(A[i][k] * B[k][j] for k in range(c1))
                    for j in range(c2)
                ]
                for i in range(r1)
            ]

            print("\nResult Matrix:")

            for row in result:
                print(*row)

except ValueError:
    print("Enter valid integers!")