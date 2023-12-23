# Author: JustKitkat

inp=input
def sin(): return [i for i in inp().split()]
def iin(): return [int(i) for i in inp().split()]
def fin(): return [float(i) for i in inp().split()]
def iinp(): return int(inp())
def finp(): return float(inp())

for i in range(int(inp())): # Testcases
    res=""
    c=inp()
    for i in range(8):

        if i+1!=int(c[1]):res+=c[0]+str(i+1)+"\n"
    
    for i in "abcdefgh":
        if i!=c[0]:res+=i+c[1]+"\n"
    print(res[:-1])
