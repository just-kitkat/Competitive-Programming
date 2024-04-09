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
    n=iinp()
    m={}
    a=iin()
    for i in a:
        if i in m:m[i]+=1
        else: m[i]=1
    ans=0
    for i in m:
        if m[i]==0:continue
        xo=i^2147483647
        if(xo not in m):
            ans+=m[i]
        else:
            ans+=max(m[xo], m[i])
            m[xo]=0
        
    return ans

def main():
    for i in range(iinp()): # Testcases
        print(solve(i))

main()