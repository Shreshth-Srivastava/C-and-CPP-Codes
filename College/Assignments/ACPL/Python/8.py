import os

def word_count_file(input_file, output_file):
    with open(input_file, 'r') as f:
        text = f.read().split()
    count = {}
    for word in text:
        count[word] = count.get(word, 0) + 1
    with open(output_file, 'w') as f:
        for word in sorted(count):
            f.write(f"{word}: {count[word]}\n")

if __name__ == "__main__":
    script_directory = os.path.dirname(__file__)
    input_file = os.path.join(script_directory, "8_Input_file.txt")
    output_file = os.path.join(script_directory, "8_Output_file.txt")
    word_count_file(input_file, output_file)