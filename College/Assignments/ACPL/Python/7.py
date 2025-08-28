def longest_word_length(words):
    return max(len(word) for word in words)

if __name__ == "__main__":
    words = ["A", "AB", "ABC", "DE", "F"]
    print(longest_word_length(words))