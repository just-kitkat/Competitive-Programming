# Author: JustKitkat

inp=input
def sin(): return [i for i in inp().split()]
def iin(): return [int(i) for i in inp().split()]
def fin(): return [float(i) for i in inp().split()]
def iinp(): return int(inp())
def finp(): return float(inp())

for i in range(iinp()): # Testcases
    res=0
    n=inp()
    c=1
    for i in n:
        i=int(i)
        if i==0:i=10
        res+=abs(i-c)
        c=i


    print(res+4)

