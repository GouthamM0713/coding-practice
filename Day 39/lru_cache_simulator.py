class LRUCache:
    def __init__(self, capacity):
        self.capacity = capacity
        self.cache = {}

    def get(self, key):
        if key not in self.cache:
            return -1

        value = self.cache.pop(key)
        self.cache[key] = value
        return value

    def put(self, key, value):
        if key in self.cache:
            self.cache.pop(key)

        elif len(self.cache) >= self.capacity:
            removed = next(iter(self.cache))
            del self.cache[removed]
            print("Evicted:", removed)

        self.cache[key] = value

    def display(self):
        print("Cache:", self.cache)


cache = LRUCache(3)

cache.put(1, "Python")
cache.put(2, "Java")
cache.put(3, "C++")
cache.display()

print("Access:", cache.get(1))

cache.put(4, "JavaScript")
cache.display()
