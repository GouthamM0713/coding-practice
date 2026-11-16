import re

filename = input("Enter Markdown filename: ")

try:
    with open(filename, "r", encoding="utf-8") as file:
        lines = file.readlines()

    html = []

    for line in lines:
        line = line.strip()

        if line.startswith("### "):
            html.append(f"<h3>{line[4:]}</h3>")

        elif line.startswith("## "):
            html.append(f"<h2>{line[3:]}</h2>")

        elif line.startswith("# "):
            html.append(f"<h1>{line[2:]}</h1>")

        elif line.startswith("- "):
            html.append(f"<li>{line[2:]}</li>")

        elif line:
            line = re.sub(
                r"\*\*(.*?)\*\*",
                r"<strong>\1</strong>",
                line
            )
            html.append(f"<p>{line}</p>")

    output = "\n".join(html)

    with open("converted.html", "w", encoding="utf-8") as file:
        file.write("<html><body>\n")
        file.write(output)
        file.write("\n</body></html>")

    print("HTML file created: converted.html")

except FileNotFoundError:
    print("Markdown file not found!")