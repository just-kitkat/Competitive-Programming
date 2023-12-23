# Author: JustKitkat

inp=input
def sin(): return [i for i in inp().split()]
def iin(): return [int(i) for i in inp().split()]
def fin(): return [float(i) for i in inp().split()]
def iinp(): return int(inp())
def finp(): return float(inp())
for i in range(int(inp())): # Testcases
    res=0
    n=iinp()
    s=inp()
    m,lett=-1,""
    p={}
    for i in s:
        if i in p:
            p[i]+=1
        else:
            p[i]=1
        if p[i]>m:m,lett=p[i],i
    
    if m<=n-m:res=0
    else:res=m-n+m

    if n%2==1 and res==0:res=1
    print(res)