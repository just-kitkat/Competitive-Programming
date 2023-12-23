# Author: JustKitkat
#tle
inp=input
def sin(): return [i for i in inp().split()]
def iin(): return [int(i) for i in inp().split()]
def fin(): return [float(i) for i in inp().split()]
def iinp(): return int(inp())
def finp(): return float(inp())

for i in range(int(inp())): # Testcases
    res=0
    p=""
    n=iinp()
    f=iin()

    for i in range(n):
        res=0
        a=f.copy()
        s=a[i]
        a.pop(i)
        a.sort(reverse=1)
        for x in a[::-1]:
            if s>=a[-1]:
                s+=a[-1]
                a.pop()
                res+=1
            else:
                break
        p+=f"{res} "
    print(p[:-1])
