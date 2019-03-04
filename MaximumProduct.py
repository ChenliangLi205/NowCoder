if __name__ == '__main__':
    length = input()
    A = input().split()
    A = list(map(int, A))
    if len(A) <= 2:
        print(0)
    elif len(A) == 3:
        print(A[0]*A[1]*A[2])
    else:
        nQ = []
        pQ = []
        maxVal = max(A)
        for n in A:
            if len(nQ) == 0:
                nQ.append(n)
            elif len(nQ) == 1:
                if n < nQ[0]:
                    nQ.insert(0, n)
                else:
                    nQ.append(n)
            else:
                if n < nQ[0]:
                    nQ.insert(0,n)
                    nQ.pop(-1)
                elif n < nQ[1]:
                    nQ.insert(1,n)
                    nQ.pop(-1)
                else:
                    pass

            if len(pQ) == 0:
                pQ.append(n)
            elif len(pQ) == 1:
                if n > pQ[0]:
                    pQ.append(n)
                else:
                    pQ.insert(0,n)
            elif len(pQ) == 2:
                if n > pQ[1]:
                    pQ.append(n)
                elif n > pQ[0]:
                    pQ.insert(1,n)
                else:
                    pQ.insert(0,n)
            else:
                if n > pQ[2]:
                    pQ.append(n)
                    pQ.pop(0)
                elif n > pQ[1]:
                    pQ.insert(2, n)
                    pQ.pop(0)
                elif n > pQ[0]:
                    pQ.insert(1, n)
                    pQ.pop(0)
                else:
                    pass
        print(max(nQ[0]*nQ[1]*maxVal, pQ[0]*pQ[1]*pQ[2]))