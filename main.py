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
    print(tc)

def main():
    tc = 1
    # tc = iinp()
    for i in range(1, tc + 1): # Testcases
        solve(i)

main()