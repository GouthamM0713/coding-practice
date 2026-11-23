text = input("Enter a paragraph: ")

words = text.split()
sentences = text.count(".") + text.count("!") + text.count("?")

print("\nText Statistics")
print("Characters:", len(text))
print("Characters without spaces:", len(text.replace(" ", "")))
print("Words:", len(words))
print("Sentences:", sentences)
print("Average word length:",
      round(sum(len(word) for word in words) / len(words), 2)
      if words else 0)