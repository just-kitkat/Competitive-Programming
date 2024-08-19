# Author: JustKitkat
# Status: AC
# Atcoder ABC F

inp=input
inf=float('inf')

def sin(): return [i for i in inp().split()]
def iin(): return [int(i) for i in inp().split()]
def fin(): return [float(i) for i in inp().split()]
def iinp(): return int(inp())
def finp(): return float(inp())
import random
def solve(tc):
    n,q = iin()
    a=iin()
    b=iin()
    m={}
    for ind,i in enumerate(a):
        if i in m: a[ind]=m[i]
        else:
            r=random.randint(1,1000000000)
            a[ind], m[i] = r,r
    for ind,i in enumerate(b):
        if i in m: b[ind]=m[i]
        else:
            r=random.randint(1,1000000000)
            b[ind], m[i] = r,r
    for i in range(1,n): 
        a[i]+=a[i-1]
        b[i]+=b[i-1]
    
    for i in range(q):
        l,r,L,R = iin()
        if l-r != L-R or \
        a[r-1] - (0 if l-2<0 else a[l-2]) != \
        b[R-1] - (0 if L-2<0 else b[L-2]): print("No")
        else: print("Yes")
    

def main():
    tc = 1
    # tc = iinp()
    for i in range(tc): # Testcases
        solve(i)

main()