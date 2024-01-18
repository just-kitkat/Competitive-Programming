# Author: JustKitkat
# Status: WIP
# python test

inp=input
inf=float('inf')

def sin(): return [i for i in inp().split()]
def iin(): return [int(i) for i in inp().split()]
def fin(): return [float(i) for i in inp().split()]
def iinp(): return int(inp())
def finp(): return float(inp())

def solve(tc):
    iin()
    a,b=iin(),iin()
    a.sort()
    b.sort()
    ans=0
    a1,a2,b1,b2=0,len(a)-1,0,len(b)-1
    while(a1<=a2):
        if abs(a[a1]-b[b2])>abs(a[a2]-b[b1]):
            ans+=abs(a[a1]-b[b2])
            a1+=1
            b2-=1
        else:
            ans+=abs(a[a2]-b[b1])
            a2-=1
            b1+=1
    
    return ans

def main():
    for i in range(iinp()): # Testcases
        print(solve(i))

main()