import re


def format_phone_number(number):
    digits = re.sub(r"\D", "", number)

    if len(digits) == 12 and digits.startswith("91"):
        digits = digits[2:]

    if len(digits) != 10 or digits[0] not in "6789":
        return None

    return f"+91 {digits[:5]} {digits[5:]}"


number = input("Enter mobile number: ")

formatted = format_phone_number(number)

if formatted:
    print("Formatted number:", formatted)
else:
    print("Invalid Indian mobile number.")

    