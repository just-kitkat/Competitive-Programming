# Author: JustKitkat
# TLE Test 19

inp=input
inf=float('inf')
def sin(): return [i for i in inp().split()]
def iin(): return [int(i) for i in inp().split()]
def fin(): return [float(i) for i in inp().split()]
def iinp(): return int(inp())
def finp(): return float(inp())

for i in range(iinp()): # Testcases
    res=0
    n,m=iin()
    vv=m*n
    vvc=0
    v=[[0 for i in range(m)] for i in range(n)]
    a=[]
    for i in range(n):
        a.append(iin())

    for p in range(n):
        for l in range(m):
            if v[p][l]:
                continue
            if a[p][l]==0:
                vvc+=1
                v[p][l]=1
                continue
            st=[[(p,l)]]
            s=a[p][l]
            v[p][l]=1
            while st[-1]!=[]:
                st.append([])
                for j,k in st[-2]:
                    if j>0 and a[j-1][k] and not v[j-1][k]:
                        j-=1
                        c=a[j][k]
                        st[-1].append((j,k))
                        v[j][k]=1
                        vvc+=1
                        s+=c
                        j+=1
                    if j<len(a)-1 and a[j+1][k] and not v[j+1][k]:
                        j+=1
                        c=a[j][k]
                        st[-1].append((j,k))
                        v[j][k]=1
                        vvc+=1
                        s+=c
                        j-=1
                    if k<len(a[0])-1 and a[j][k+1] and not v[j][k+1]:
                        k+=1
                        c=a[j][k]
                        st[-1].append((j,k))
                        v[j][k]=1
                        vvc+=1
                        s+=c
                        k-=1
                    if k>0 and a[j][k-1] and not v[j][k-1]:
                        k-=1
                        c=a[j][k]
                        st[-1].append((j,k))
                        s+=c
                        v[j][k]=1
                        vvc+=1
                        k+=1
            res=max(s,res)
    print(res)
