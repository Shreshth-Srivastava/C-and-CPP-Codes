def find_absent_digits(mobile):
    all_digits = set("0123456789")
    present_digits = set(mobile)
    if len(mobile) != 10:
        print("Invalid mobile number")
        return
    result = ""
    temp = sorted(all_digits - present_digits)
    if(len(temp) != 0):
        for i in temp:
            result += " " + i
    else:
        result = "No absent digits"
    print(result)

def main():
    s = input("Enter mobile number: ")
    find_absent_digits(s)

if __name__ == "__main__":
    main()