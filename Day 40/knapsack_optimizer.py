def knapsack(weights, values, capacity):
    n = len(weights)

    dp = [
        [0] * (capacity + 1)
        for _ in range(n + 1)
    ]

    for i in range(1, n + 1):
        for w in range(capacity + 1):

            if weights[i - 1] <= w:
                include = (
                    values[i - 1]
                    + dp[i - 1][w - weights[i - 1]]
                )

                exclude = dp[i - 1][w]

                dp[i][w] = max(include, exclude)

            else:
                dp[i][w] = dp[i - 1][w]

    selected = []
    w = capacity

    for i in range(n, 0, -1):
        if dp[i][w] != dp[i - 1][w]:
            selected.append(i - 1)
            w -= weights[i - 1]

    selected.reverse()

    return dp[n][capacity], selected


weights = [2, 3, 4, 5]
values = [3, 4, 5, 6]
capacity = 8

maximum, selected = knapsack(
    weights, values, capacity
)

print("Maximum value:", maximum)
print("Selected items:")

for index in selected:
    print(
        f"Item {index + 1}: "
        f"Weight={weights[index]}, "
        f"Value={values[index]}"
    )