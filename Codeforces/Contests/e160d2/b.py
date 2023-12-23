# Author: JustKitkat

inp=input
def sin(): return [i for i in inp().split()]
def iin(): return [int(i) for i in inp().split()]
def fin(): return [float(i) for i in inp().split()]
def iinp(): return int(inp())
def finp(): return float(inp())

for i in range(iinp()): # Testcases
    res=0
    s=inp()

    emp=len(s)
    n0,n1=0,0
    res=emp
    for i in s:
        n0+=i=="0"
        n1+=i=="1"
    for i in s:
        emp-=1
        n0-=i=="1"
        n1-=i=="0"
        if n1<0 or n0<0:
            break
        res=emp
    
    print(res)

