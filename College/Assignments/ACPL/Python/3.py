def fibonacci(n: int) -> int:
    if(n<0):
        print("Invalid value of n")
        return -1
    if(n == 1 or n == 0):
        return 1
    return fibonacci(n-1) + fibonacci(n-2)

if __name__ == "__main__":
    print(fibonacci(5))