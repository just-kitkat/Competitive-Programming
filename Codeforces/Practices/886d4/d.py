# Author: JustKitkat
# Status: WIP

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
    a=iin()
    a.sort()
    
    p=a[0]
    l=0
    for i in a:
        if i-p>k:
            res=max(res,l)
            l=1
        else:
            l+=1
        p=i
    res=max(res,l)
    res=len(a)-res
    return res

def main():
    for i in range(iinp()): # Testcases
        print(solve(i))

main()