inp=input
def sin(): return [i for i in inp().split()]
def iin(): return [int(i) for i in inp().split()]
def fin(): return [float(i) for i in inp().split()]
def iinp(): return int(inp())
def finp(): return float(inp())

for i in range(int(inp())): # Testcases
    res=iinp()
    res="First" if (res+1)%3==0 or (res-1)%3==0 else "Second"
    
    print(res)
