def longest_palindrome(s):
    result = ""
    for i in range(len(s)):
        for j in range(i, len(s)):
            substr = s[i:j+1]
            if substr == substr[::-1] and len(substr) > len(result):
                result = substr
    return result

if __name__ == "__main__":
    print(longest_palindrome("cbbd"))