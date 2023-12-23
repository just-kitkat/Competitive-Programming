# Author: JustKitkat
# cant solve

inp=input
def sin(): return [i for i in inp().split()]
def iin(): return [int(i) for i in inp().split()]
def fin(): return [float(i) for i in inp().split()]
def iinp(): return int(inp())
def finp(): return float(inp())

for i in range(iinp()): # Testcases
    res=0
    n=iinp()
    s=[]
    ma=0
    for i in range(n):
        x=iin()
        s.append(x)
        if ma<x[1]-x[0]:
            ma=x[1]-x[0]
    low,upp=0,ma
    print(f"{ma=}")

    #bin search
    k=upp-low
    k//=2
    c=k
    while low!=k:
        fl=1
        for i in range(n):
            x=s[i]
            if x[0]<=c<=x[1]:
                c+=k
                continue
            else:
                if c<x[0]:
                    upp=k
                else:
                    low=k
                k=upp-low
                k//=2
                fl=0
            print(k,x,c,upp,low)
        if fl:break

    res=k

    print(res)
