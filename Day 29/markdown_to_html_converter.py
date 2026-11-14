import re
from html import escape

def convert_markdown(text):
    lines = text.splitlines()
    result = []
    in_list = False

    for line in lines:
        line = escape(line)

        if line.startswith("# "):
            if in_list:
                result.append("</ul>")
                in_list = False
            result.append(f"<h1>{line[2:]}</h1>")

        elif line.startswith("## "):
            if in_list:
                result.append("</ul>")
                in_list = False
            result.append(f"<h2>{line[3:]}</h2>")

        elif line.startswith("- "):
            if not in_list:
                result.append("<ul>")
                in_list = True
            result.append(f"<li>{line[2:]}</li>")

        else:
            if in_list:
                result.append("</ul>")
                in_list = False

            if line.strip():
                line = re.sub(
                    r"\*\*(.+?)\*\*",
                    r"<strong>\1</strong>",
                    line
                )
                line = re.sub(
                    r"\*(.+?)\*",
                    r"<em>\1</em>",
                    line
                )
                result.append(f"<p>{line}</p>")

    if in_list:
        result.append("</ul>")

    return "\n".join(result)


content = input("Enter Markdown text: ")

html = convert_markdown(content)

print("\nConverted HTML:\n")
print(html)

with open("converted.html", "w", encoding="utf-8") as file:
    file.write(html)

print("\nSaved as converted.html")