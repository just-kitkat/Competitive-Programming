#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define FOR(a,b) for(int i=a;i<b;++i)
#define ii pair<int,int>

signed main(){
    int n;
    cin>>n;
    vi a(n),b(n);
    for(auto &x:a)cin>>x;
    for(auto &x:b)cin>>x;
    int ans=0;
    FOR(0,n)ans+=min(a[i],b[i]);
    cout<<ans;

}