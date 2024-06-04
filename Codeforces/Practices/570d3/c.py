# // Author: JustKitkat
# // Status: WIP

def solve(tc):
    k,n,a,b=[int(i)for i in input().split(" ")]
    if(b*n>=k):
        print(-1)
        return
    lo=0
    hi=n
    while(lo<hi):
        mid=(lo+hi)//2
        if(mid*a+(n-mid)*b>=k):hi=mid-1
        #// if(mid*a+(n-mid)*b<k)lo=mid+1;
        else: lo=mid+1
        # // else {cout<<mid<<el;return;}

    print(lo-1 if (lo)*a+(n-lo)*b>=k else lo)


def main():
    for i in range(int(input())):
        solve(i)
main()