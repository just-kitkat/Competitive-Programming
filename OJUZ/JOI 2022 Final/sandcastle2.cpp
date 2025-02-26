#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int h,w;
    cin>>h>>w;
    vi a(w);for(auto &x:a)cin>>x;
    int n=w;
    int p=0,ans=0;
    int prev=0,cnt=0;
    for(int i=0;i<n;++i){
        if(a[i]>prev)ans+=cnt,cnt++;
        else cnt=1;
        prev=a[i];
        // cout<<a[i]<<' '<<ans<<endl;
    }
    reverse(a.begin(),a.end());
    prev=0,cnt=0;
    for(int i=0;i<n;++i){
        if(a[i]>prev)ans+=cnt,cnt++;
        else cnt=1;
        prev=a[i];
    }
    cout<<ans+w;

}   