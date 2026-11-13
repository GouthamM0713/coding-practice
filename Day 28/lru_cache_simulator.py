from collections import OrderedDict


class LRUCache:
    def __init__(self, capacity):
        self.capacity = capacity
        self.cache = OrderedDict()

    def get(self, key):
        if key not in self.cache:
            return -1

        self.cache.move_to_end(key)
        return self.cache[key]

    def put(self, key, value):
        if self.capacity <= 0:
            return

        if key in self.cache:
            self.cache.move_to_end(key)

        self.cache[key] = value

        if len(self.cache) > self.capacity:
            removed = self.cache.popitem(last=False)
            print("Removed least recently used item:", removed)

    def display(self):
        print("Current cache:", dict(self.cache))


capacity = int(input("Enter cache capacity: "))

if capacity <= 0:
    print("Capacity must be positive.")

else:
    cache = LRUCache(capacity)

    while True:
        print("\n1. Add or Update")
        print("2. Get Value")
        print("3. Display Cache")
        print("4. Exit")

        choice = input("Enter choice: ")

        if choice == "1":
            key = input("Enter key: ")
            value = input("Enter value: ")

            cache.put(key, value)
            print("Item added or updated.")

        elif choice == "2":
            key = input("Enter key: ")
            result = cache.get(key)

            if result == -1:
                print("Key not found.")
            else:
                print("Value:", result)

        elif choice == "3":
            cache.display()

        elif choice == "4":
            print("Exiting LRU Cache.")
            break

        else:
            print("Invalid choice.")