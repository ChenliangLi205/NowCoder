def Validate(num, tar):
    v = 0
    while num>0:
        v += num
        num //= 10
    return v == tar

if __name__ == '__main__':
    s = input()
    digits = len(s)
    s = int(s)
    chushu = 1
    chenshu = 1
    for i in range(digits-1):
        chenshu*=10
        chushu = chushu*10+1
    success = False
    res = -1
    for n in range(s, s+digits):
        res = (n * chenshu) // chushu
        if Validate(res, s):
            success = True
            break
    if not success:
        res = -1
    print(res)