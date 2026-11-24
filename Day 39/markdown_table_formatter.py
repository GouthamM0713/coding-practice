def create_markdown_table(data):
    rows = [
        [cell.strip() for cell in line.split(",")]
        for line in data.strip().splitlines()
    ]

    if not rows:
        return "No data provided."

    columns = len(rows[0])

    if any(len(row) != columns for row in rows):
        return "Error: All rows must have equal columns."

    widths = [
        max(len(row[i]) for row in rows)
        for i in range(columns)
    ]

    def format_row(row):
        return "| " + " | ".join(
            row[i].ljust(widths[i])
            for i in range(columns)
        ) + " |"

    header = format_row(rows[0])

    separator = "| " + " | ".join(
        "-" * widths[i]
        for i in range(columns)
    ) + " |"

    body = [
        format_row(row)
        for row in rows[1:]
    ]

    return "\n".join([header, separator] + body)


data = """Name,Age,Course
Goutham,20,CSE
Rahul,21,ECE
Priya,19,ISE"""

print(create_markdown_table(data))