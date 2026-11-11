import xml.etree.ElementTree as ET

filename = input("Enter XML filename: ")

try:
    tree = ET.parse(filename)
    root = tree.getroot()

    print("\nXML DATA")
    print("Root Element:", root.tag)

    for element in root:
        print("\nElement:", element.tag)
        print("Attributes:", element.attrib)
        print("Value:", element.text.strip() if element.text else "")

except FileNotFoundError:
    print("XML file not found.")

except ET.ParseError:
    print("Invalid XML format.")

except OSError as error:
    print("File error:", error)