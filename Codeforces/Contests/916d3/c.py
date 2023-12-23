# Author: JustKitkat
# AC after contest

inp=input
inf=float('inf')

def sin(): return [i for i in inp().split()]
def iin(): return [int(i) for i in inp().split()]
def fin(): return [float(i) for i in inp().split()]
def iinp(): return int(inp())
def finp(): return float(inp())

def solve(tc):
    res=0
    n,k=iin()
    a,b=iin(),iin()
    mb=b[0]
    s=0
    if k ==1:return a[0]
    for i in range(n):
        s+=a[i]
        if i+1==k:
            res=max(res,s)
            break
        mb=mb if b[i]<mb else b[i]
        res=max(res,s+mb*(k-i-1))

    
    return res

def main():
    for i in range(iinp()): # Testcases
        print(solve(i))

main()