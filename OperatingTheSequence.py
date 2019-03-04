def get(a):
    if len(a) == 0:
        return []
    if len(a) == 1:
        return [a[0]]
    b = []
    lastIdx = len(a)-1
    while lastIdx >= 0:
        b.append(a[lastIdx])
        a.pop(lastIdx)
        lastIdx -= 2
    for n in a:
        b.append(n)
    return b

if __name__ == '__main__':
    length = input()
    array = list(map(int, input().split()))
    a = list(map(str, get(array)))
    print(' '.join(a))