import heapq
from collections import Counter


def build_huffman_tree(text):
    frequency = Counter(text)
    heap = []

    for char, freq in frequency.items():
        heapq.heappush(heap, (freq, char, {
            "char": char
        }))

    if not heap:
        return None

    while len(heap) > 1:
        freq1, _, left = heapq.heappop(heap)
        freq2, _, right = heapq.heappop(heap)

        merged = {
            "left": left,
            "right": right
        }

        heapq.heappush(
            heap,
            (freq1 + freq2, min(str(left), str(right)), merged)
        )

    return heap[0][2]


def generate_codes(node, code="", codes=None):
    if codes is None:
        codes = {}

    if node is None:
        return codes

    if "char" in node:
        codes[node["char"]] = code or "0"
        return codes

    generate_codes(node["left"], code + "0", codes)
    generate_codes(node["right"], code + "1", codes)

    return codes


text = input("Enter text to encode: ")

tree = build_huffman_tree(text)

if tree is None:
    print("No text entered.")
else:
    codes = generate_codes(tree)

    encoded = "".join(codes[char] for char in text)

    print("\nHuffman Codes:")

    for char, code in codes.items():
        print(repr(char), ":", code)

    print("\nEncoded text:", encoded)
    print("Original bits:", len(text) * 8)
    print("Encoded bits:", len(encoded))