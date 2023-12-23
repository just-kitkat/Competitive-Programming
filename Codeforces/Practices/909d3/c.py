inp=input
def sin(): return [i for i in inp().split()]
def iin(): return [int(i) for i in inp().split()]
def fin(): return [float(i) for i in inp().split()]
def iinp(): return int(inp())
def finp(): return float(inp())

for i in range(int(inp())): # Testcases
    n=iinp()
    a=iin()
    if n==1:
        print(a[0])
        continue
    p1,p2=0,0
    res=a[0]
    tmp=abs(a[0]%2)
    t=a[0]
    while p2 < n-1:
        if abs(a[p2+1]%2)==tmp:
            while p1<p2:
                t-=a[p1]
                p1+=1
                res=max(res,t)
            p1,p2=p2+1,p2+1
            t=a[p1]
            tmp=abs(a[p2]%2)

        else:
            p2+=1
            t+=a[p2]
            res=max(res,t)

            tmp=abs(a[p2]%2)
        print(f"{t=}")
    while p1<p2:
        t-=a[p1]
        p1+=1
        res=max(res,t)
    res=max(res,t)
    print(res)
