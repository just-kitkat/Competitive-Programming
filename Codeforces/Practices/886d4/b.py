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
    m=0
    n=iinp()
    for i in range(n):
        a,b=iin()
        if a<=10:
            if m<b:
                res=i+1
                m=b
    
    return res

def main():
    for i in range(iinp()): # Testcases
        print(solve(i))

main()