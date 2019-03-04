def judge(x,f,d,p):
    if f!=0 and f*x > d:
        return int(d/x)
    ans = f
    d -= f*x
    return ans + int(d/(x+p))

if __name__ == '__main__':
    [x,f,d,p] = list(map(int, input().split()))
    print(judge(x,f,d,p))