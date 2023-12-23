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
    a,b,c=iin()
    if a+b>=10 or b+c>=10 or c+a>=10:res="YES"
    else:res="NO"
    
    return res

def main():
    for i in range(iinp()): # Testcases
        print(solve(i))

main()