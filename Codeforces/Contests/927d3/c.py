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
    n,m=iin()
    a=iin()
    pdt=1
    for i in a:pdt*=i
    l,r=0,n-1
    s=inp()
    if(n==1):
        print(a[0]%m)
        return
    s=s[:-1]
    ans=[]
    ans.append(pdt%m)
    for x in s:
        if(x=='L'):
            pdt//=a[l]
            l+=1
        else:
            pdt//=a[r]
            r-=1
        
        ans.append(pdt%m)
    
    print(" ".join([str(i)for i in ans]))
    
    #return res

def main():
    for i in range(iinp()): # Testcases
        solve(i)#print(solve(i))

main()