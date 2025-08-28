def replace_words(text):
    return text.replace("Python", "#").replace("Java", "Python").replace("#", "Java")

if __name__ == "__main__":
    text = "Python and Java are object-oriented programming languages. JavaScript is not related to Java. Python is used for Django and Java is used for springboot."
    print(replace_words(text))