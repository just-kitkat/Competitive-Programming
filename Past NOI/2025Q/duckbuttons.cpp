#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define FOR(a,b) for(int i=a;i<b;++i)
#define ii pair<int,int>

signed main(){
    int n,d;
    cin>>n>>d;
    vi a(n);
    for(auto &x:a)cin>>x;
    int ans=0,left=d,prevmax=0;
    for(int i=n-1;i>0;--i){
        if(a[i]>prevmax){
            ans+=(a[i]-prevmax)*i;
            prevmax=a[i];
        }
        // cout<<a[i]<<' '<<prevmax<<' '<<ans<<endl;
    }
    cout<<ans;

}