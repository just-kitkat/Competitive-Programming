# Author: JustKitkat

inp=input
def sin(): return [i for i in inp().split()]
def iin(): return [int(i) for i in inp().split()]
def fin(): return [float(i) for i in inp().split()]
def iinp(): return int(inp())
def finp(): return float(inp())
inf=float("inf")
for i in range(iinp()): # Testcases
    res=0
    s=[]
    min11=inf
    for i in range(iinp()):
        a,b=sin()
        if b=="00":
            continue
        else:
            a=int(a)
            s.append([a, b])
            if a<min11 and b=="11":
                min11=a
    
    m10,m01=inf,inf
    for i in s:
        if i[1]=="10" and i[0]<m10:m10=i[0]
        elif i[1]=="01" and i[0]<m01:m01=i[0]
    res=min(min11,m10+m01)
    
    print(res if res!=inf else -1)

