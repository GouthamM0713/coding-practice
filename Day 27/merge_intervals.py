def merge_intervals(intervals):
    if not intervals:
        return []

    intervals.sort(key=lambda x: x[0])

    merged = [intervals[0]]

    for current in intervals[1:]:
        last = merged[-1]

        if current[0] <= last[1]:
            last[1] = max(last[1], current[1])
        else:
            merged.append(current)

    return merged


intervals = []

try:
    n = int(input("Enter number of intervals: "))

    if n < 0:
        print("Number of intervals cannot be negative.")
    else:
        for i in range(n):
            print(f"\nInterval {i + 1}")

            start = int(input("Start: "))
            end = int(input("End: "))

            if start > end:
                print("Start cannot be greater than end.")
                intervals = []
                break

            intervals.append([start, end])

        if intervals or n == 0:
            result = merge_intervals(intervals)
            print("\nMerged intervals:", result)

except ValueError:
    print("Please enter valid integers.")