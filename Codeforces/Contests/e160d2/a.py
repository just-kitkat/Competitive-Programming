# Author: JustKitkat

inp=input
def sin(): return [i for i in inp().split()]
def iin(): return [int(i) for i in inp().split()]
def fin(): return [float(i) for i in inp().split()]
def iinp(): return int(inp())
def finp(): return float(inp())

for i in range(iinp()): # Testcases
    res=0
    ab=inp()
    a,b=-1,-1
    p=len(ab)-1
    while p!=0:
        a,b=ab[:p],ab[p:]
        if b[0]!="0" and int(a)<int(b):
            break
        p-=1
    res=a+" "+b
    if p==0:res=-1

    
    print(res)

