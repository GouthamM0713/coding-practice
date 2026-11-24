import ipaddress


def calculate_subnet(ip, prefix):
    try:
        network = ipaddress.ip_network(
            f"{ip}/{prefix}",
            strict=False
        )

        print("\n--- Subnet Information ---")
        print("Network Address:", network.network_address)
        print("Broadcast Address:", network.broadcast_address)
        print("Subnet Mask:", network.netmask)
        print("Wildcard Mask:", network.hostmask)
        print("Prefix Length:", network.prefixlen)
        print("Total Addresses:", network.num_addresses)

        if network.version == 4:
            print("Usable Hosts:", network.num_addresses - 2)

            if network.num_addresses > 2:
                print("First Host:", network.network_address + 1)
                print("Last Host:", network.broadcast_address - 1)

    except ValueError as error:
        print("Invalid input:", error)


ip = input("Enter IPv4 address: ")
prefix = input("Enter prefix length (0-32): ")

try:
    prefix = int(prefix)

    if not 0 <= prefix <= 32:
        print("Prefix must be between 0 and 32.")
    else:
        calculate_subnet(ip, prefix)

except ValueError:
    print("Prefix must be an integer.")