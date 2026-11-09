import json

data = input("Enter JSON data: ")

try:
    parsed = json.loads(data)

    print("\nValid JSON")
    print("Formatted JSON:")

    print(json.dumps(parsed, indent=4))

except json.JSONDecodeError as error:
    print("Invalid JSON")
    print("Error:", error)