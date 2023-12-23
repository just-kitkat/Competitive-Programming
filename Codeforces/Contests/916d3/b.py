# Author: JustKitkat
# AC

inp=input
inf=float('inf')

def sin(): return [i for i in inp().split()]
def iin(): return [int(i) for i in inp().split()]
def fin(): return [float(i) for i in inp().split()]
def iinp(): return int(inp())
def finp(): return float(inp())

def solve(tc):
    res=[]
    n,k=iin()
    c=1
    for i in range(k):
        res.append(n)
        n-=1
    for i in range(n):
        res.append(c)
        c+=1
    res=res[::-1]
    res=" ".join([str(i) for i in res])
    
    return res

def main():
    for i in range(iinp()): # Testcases
        print(solve(i))

main()