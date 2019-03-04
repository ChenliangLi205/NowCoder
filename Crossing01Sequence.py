def find(s):
    if len(s) == 0:
        return 0
    if len(s) == 1:
        return 1
    maxLen = 0
    currLen = 1
    currChar = s[0]
    for i in range(1, len(s)):
        if s[i] != currChar:
            currLen += 1
            currChar = s[i]
        else:
            maxLen = max(maxLen, currLen)
            currLen = 1
            currChar = s[i]
    return max(maxLen, currLen)

if __name__ == '__main__':
    s = input()
    print(find(s))