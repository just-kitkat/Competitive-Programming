# Author: JustKitkat
# error
inp=input
inf=float('inf')

def sin(): return [i for i in inp().split()]
def iin(): return [int(i) for i in inp().split()]
def fin(): return [float(i) for i in inp().split()]
def iinp(): return int(inp())
def finp(): return float(inp())
def solve(tc):
    res=0
    n=iinp()
    p=[]
    total=[]
    for i in range(n):
        p.append(iin())
    for i in range(n):
        total.append(p[i][0])
    for f in range(n):
        s=0
        while s<(1<<3):
            total[s][f]=total[s][f-1]
            for x in range(3):
                if s&(1<<x):
                    total[s][f]=min(total[s][f],total[s^(1<<x)][f-1]+p[x][f])
            s+=1
    
    return res

def main():
    for i in range(iinp()): # Testcases
        print(solve(i))

main()