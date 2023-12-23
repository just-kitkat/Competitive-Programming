# Author: JustKitkat

inp=input
def sin(): return [i for i in inp().split()]
def iin(): return [int(i) for i in inp().split()]
def fin(): return [float(i) for i in inp().split()]
def iinp(): return int(inp())
def finp(): return float(inp())
from functools import lru_cache as cache


for i in range(iinp()): # Testcases
    res=0
    n,k=iin()
    a=iin()
    even,odd=0,0
    mi = float("inf")
    for i in a:
        if i%k==0:
            mi=0
            break
        
        if mi>k-abs(i%k):
            mi=k-abs(i%k)
        if k==4:
            if i%2==0:even+=1
            else:odd+=1
    if k==4:
        if odd>1:mi=2 if mi>2 else mi
        if even>1:mi=0
        if even==1 and odd>0:mi=1 if mi!=0 else 0
    res=mi

    print(res)

