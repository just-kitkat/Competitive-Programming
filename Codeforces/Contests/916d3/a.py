# Author: JustKitkat
# AC

inp=input
inf=float('inf')

def sin(): return [i for i in inp().split()]
def iin(): return [int(i) for i in inp().split()]
def fin(): return [float(i) for i in inp().split()]
def iinp(): return int(inp())
def finp(): return float(inp())

def solve(tc):
    res=0
    a={}
    n=inp()
    m=inp()
    for l in m:
        if l in a:
            a[l]+=1
        else:
            a[l]=1
    for i in a:
        if ord(i)-64<=a[i]:res+=1
    
    
    return res

def main():
    for i in range(iinp()): # Testcases
        print(solve(i))

main()