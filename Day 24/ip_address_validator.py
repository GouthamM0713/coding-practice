import ipaddress

ip = input("Enter IP address: ")

try:
    address = ipaddress.ip_address(ip)

    print("Valid IP Address")
    print("Version:", address.version)
    print("Compressed:", address.compressed)

except ValueError:
    print("Invalid IP Address")