# Author: JustKitkat

inp=input
def sin(): return [i for i in inp().split()]
def iin(): return [int(i) for i in inp().split()]
def fin(): return [float(i) for i in inp().split()]
def iinp(): return int(inp())
def finp(): return float(inp())

for i in range(iinp()): # Testcases
    res=0
    s=inp()
    c=0
    a="abc"
    for i in range(len(s)):
        if s[i]==a[i]:c+=1
    
    print("YES"if c>0 else "NO")

