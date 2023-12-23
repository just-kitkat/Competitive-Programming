# Author: JustKitkat

inp=input
def sin(): return [i for i in inp().split()]
def iin(): return [int(i) for i in inp().split()]
def fin(): return [float(i) for i in inp().split()]
def iinp(): return int(inp())
def finp(): return float(inp())

for i in range(int(inp())): # Testcases
    res=0
    s=list(inp()[::-1])
    b,B=0,0

    for ind,i in enumerate(s):
        if i=="b":
            b+=1
            s[ind]=""
        elif i=="B":
            B+=1
            s[ind]=""
        else:
            if i.islower() and b:
                b-=1
                s[ind]=""
            elif i.isupper() and B:
                B-=1
                s[ind]=""
    res="".join(s[::-1])


    
    
    print(res)
