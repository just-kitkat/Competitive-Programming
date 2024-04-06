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
    h,m=inp().split(":")
    h=int(h);m=int(m)
    s="AM" if h<12 else "PM"
    if h>12:h-=12
    if h==0:h=12
    res=f"{h:02d}:{m:02d} {s}"
    
    return res

def main():
    for i in range(iinp()): # Testcases
        print(solve(i))

main()