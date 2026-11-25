class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root

        for char in word.lower():
            if char not in node.children:
                node.children[char] = TrieNode()

            node = node.children[char]

        node.is_end = True

    def autocomplete(self, prefix):
        node = self.root

        for char in prefix.lower():
            if char not in node.children:
                return []

            node = node.children[char]

        results = []

        def collect(current, word):
            if current.is_end:
                results.append(word)

            for char, child in current.children.items():
                collect(child, word + char)

        collect(node, prefix.lower())
        return results


trie = Trie()

words = [
    "python", "programming", "program",
    "project", "computer", "coding",
    "code", "college"
]

for word in words:
    trie.insert(word)

prefix = input("Enter search prefix: ")

suggestions = trie.autocomplete(prefix)

if suggestions:
    print("Suggestions:")

    for word in suggestions:
        print("-", word)
else:
    print("No suggestions found.")