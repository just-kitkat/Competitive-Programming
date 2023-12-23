# Author: JustKitkat

inp=input
inf=float('inf')
def sin(): return [i for i in inp().split()]
def iin(): return [int(i) for i in inp().split()]
def fin(): return [float(i) for i in inp().split()]
def iinp(): return int(inp())
def finp(): return float(inp())

for i in range(iinp()): # Testcases
    res="NO"
    s,t=iin()
    if s==t:
        print("YES")
        continue
    c=set()
    st=[[s]]
    f=1
    while f:
        st.append([])
        f=0
        for i in st[-2]:
            if i%3==0:
                a,b=i//3*2,i//3
                if b not in c:
                    st[-1].append(b)
                    c.add(b)
                    f=1
                if a not in c:
                    st[-1].append(a)
                    c.add(a)
                    f=1
                if b == t or a==t:
                    res="YES"
                    f=0
                    break
        st.pop(0)
    print(res)

