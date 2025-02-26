#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,q;
    cin>>n;
    vector<pair<int,int>> a(n);
    int prev=0;
    for(auto &x:a){
        int tmp;cin>>tmp;
        int cnt=1;
        while(tmp%2==0)tmp/=2,cnt*=2;
        x={cnt+prev,tmp};
        prev+=cnt;
    }
    // for(auto &x:a)cout<<x.first<<' '<<x.second<<endl;
    cin>>q;
    while(q--){
        int x;cin>>x;
        int lo=0,hi=a.size()-1;
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(a[mid].first<x)lo=mid+1;
            else hi=mid;
        }
        cout<<a[lo].second<<'\n';
    }

}