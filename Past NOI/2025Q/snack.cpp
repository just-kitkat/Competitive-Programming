#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define FOR(a,b) for(int i=a;i<b;++i)
#define ii pair<int,int>


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    unordered_map<int,int>m;
    set<int>s;
    int n,q;
    cin>>n>>q;
    // node *st=new node(0,(int)1e9+5);
    // FOR(0,n){
    //     int x;cin>>x;m[x]++;
    // }
    // for(auto &x:m)st->set(x.first,x.first,x.second);


    int total=0;
    FOR(0,n){
        int x;cin>>x;
        total+=x;
        m[x]++;
        s.insert(x);
    }
    cout<<total<<'\n';
    while(q--){ // if l==r
        int l,r,val;
        cin>>l>>r>>val;
        int cnt=0;
        while(1){
            auto it=s.lower_bound(l);
            if(it!=s.end() and *it<=r);else break;
            int cc=*it;
            cnt+=m[cc];
            total-=m[cc]*(cc);
            m.erase(cc);
            s.erase(it);
        }
        total+=val*cnt;
        m[val]+=cnt;
        s.insert(val);
        cout<<total<<'\n';
    }

}