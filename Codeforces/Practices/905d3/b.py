# Author: JustKitkat

inp=input
def sin(): return [i for i in inp().split()]
def iin(): return [int(i) for i in inp().split()]
def fin(): return [float(i) for i in inp().split()]
def iinp(): return int(inp())
def finp(): return float(inp())

for i in range(iinp()): # Testcases
    res=0
    n,k=iin()
    s=inp()
    co={}
    for i in s:
        if i in co:
            co[i]+=1
        else:
            co[i]=1
    odd,even=0,0
    for i in co:
        if co[i]%2==0:even+=1
        else:odd+=1
    if odd<=k+1:
        res="YES"
    else:
        res="NO"

    print(res)

