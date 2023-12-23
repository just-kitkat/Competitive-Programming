# Author: JustKitkat

inp=input
def sin(): return [i for i in inp().split()]
def iin(): return [int(i) for i in inp().split()]
def fin(): return [float(i) for i in inp().split()]
def iinp(): return int(inp())
def finp(): return float(inp())

for i in range(iinp()): # Testcases
    res=0
    n=iinp()
    a=iin()
    m=min(a)
    f=0
    s=1
    for i in a:
        if f==0 and m==i:
            f=1
            i+=1
        s*=i
    res=s
    print(res)

