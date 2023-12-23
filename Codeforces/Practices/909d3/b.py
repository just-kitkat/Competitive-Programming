inp=input
def sin(): return [i for i in inp().split()]
def iin(): return [int(i) for i in inp().split()]
def fin(): return [float(i) for i in inp().split()]
def iinp(): return int(inp())
def finp(): return float(inp())

for i in range(int(inp())): # Testcases
    res=[]
    n=iinp()
    a=iin()
    if n==1:
        print(0)
        continue

    for i in range(1,len(a)//2+1):
        if len(a)%i==0:
            tmp=[]
            for x,_ in enumerate(a[::i]):
                tmp.append(sum(a[x*i:x*i+i]))
            res.append(max(tmp)-min(tmp))
    
    print(max(res))
