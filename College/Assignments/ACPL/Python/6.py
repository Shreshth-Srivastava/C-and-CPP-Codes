def reverse_words(s):
    return " ".join(s.split()[::-1])

if __name__ == "__main__":
    s = "Hello! My name is Shreshth Srivastava"
    print(reverse_words(s))