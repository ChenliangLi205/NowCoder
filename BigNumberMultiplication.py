def add(a,b,offset):
    bonus = 0
    bIdx = len(b)-1-offset
    aIdx = len(a)-1
    while bIdx >= 0 or aIdx >= 0:
        if aIdx >= 0 and bIdx >= 0:
            newVal = (b[bIdx] + a[aIdx] + bonus) % 10
            bonus = (b[bIdx] + a[aIdx] + bonus) // 10
            b[bIdx] = newVal
        elif aIdx < 0:
            newVal = (b[bIdx] + bonus) % 10
            bonus = (b[bIdx] + bonus) // 10
            b[bIdx] = newVal
        else:
            b.insert(0, (a[aIdx]+bonus)%10)
            bonus = (a[aIdx] + bonus) // 10
        bIdx -= 1
        aIdx -= 1
    if bonus != 0:
        b.insert(0, bonus)
    return

def multiply(a,c):
    bonus = 0
    res = []
    for char in a[::-1]:
        product = int(char) * int(c) + bonus
        res.insert(0, product%10)
        bonus = product // 10
    if bonus != 0:
        res.insert(0, bonus)
    return res

if __name__ == '__main__':
    a,b = input().split()
    if len(a) < len(b):
        a,b = b,a
    all_rows = []
    for char_b in b[::-1]:
        all_rows.append(multiply(a, char_b))
    ans = [n for n in all_rows[0]]
    for i, row in enumerate(all_rows[1:]):
        offset = i+1
        add(row, ans, offset)
    ans_str = list(map(str, ans))
    print("%s" % ''.join(ans_str))