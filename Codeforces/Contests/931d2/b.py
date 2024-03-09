# Author: JustKitkat
# Status: WIP

inp=input
inf=float('inf')

def sin(): return [i for i in inp().split()]
def iin(): return [int(i) for i in inp().split()]
def fin(): return [float(i) for i in inp().split()]
def iinp(): return int(inp())
def finp(): return float(inp())


def main():
    dp = [0]
    val=[1,3,6,10,15]
    for i in range(0,1000000000):
        dp.append(1e8)
        for j in range(4):
            dp[i]=min(dp[i],1+dp[i]-val[j])

    for i in range(iinp()): # Testcases
        print(dp[iinp()])

main()