# Author: JustKitkat

inp=input
def sin(): return [i for i in inp().split()]
def iin(): return [int(i) for i in inp().split()]
def fin(): return [float(i) for i in inp().split()]
def iinp(): return int(inp())
def finp(): return float(inp())

for i in range(iinp()): # Testcases
    res=0
    bl=0
    l=0
    inp()
    a=iin()

    for i in a:
        if i==0:
            bl+=1
            if bl>l:l=bl
        else:
            bl=0
    res=l
    
    print(res)

