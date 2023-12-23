# Author: JustKitkat

inp=input
def sin(): return [i for i in inp().split()]
def iin(): return [int(i) for i in inp().split()]
def fin(): return [float(i) for i in inp().split()]
def iinp(): return int(inp())
def finp(): return float(inp())

for i in range(int(inp())): # Testcases
    res=0
    a,b=iin()
    k=iin()
    q=iin()
    lll=list({(a,b),(a,-b),(-a,-b),(-a,b),(b,a),(-b,a),(-b,-a),(b,-a)})
    kl=[]
    for x,y in lll:
        kl.append((k[0]+x,k[1]+y))
    for pos in kl:
        for x,y in lll:
            if [pos[0]+x,pos[1]+y]==q:
                res+=1



    
    print(res)
