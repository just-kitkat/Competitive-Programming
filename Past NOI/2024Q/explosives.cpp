// NOTE: Attempted during '24 prelims (upsolving subtask)
#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>
#define pb push_back
#define FOR(a,b) for(auto i=a;i<b;++i)
#define JFOR(a,b) for(auto j=a;j<b;++j)

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n,c;cin>>n>>c;
    vi a(n),b(n);
    FOR(0,n)cin>>a[i];
    FOR(0,n)cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ans=0;
    int bi=0;
    if(c==1){
        FOR(0,n){
            ans+=abs(a[i]-b[i]);
        }
        cout<<ans<<el;
        FOR(0,n)cout<<a[i]<<' '<<b[i]<<' ';cout<<el;
    }else{
        int p=0;
        while(p<n){
            int cur = a[p];
            if(n-p<c)c=n-p+1;
            int cost = b[p+c]-cur;
            cout<<cur<<' '<<cost<<' '<<a[p]<<' '<<b[p+c]<<' '<<p<<el;
            p+=c;
            ans+=cost;
        }
        cout<<ans<<el;
    }

    return 0;
}

/*
5 3
1 2 3 4 5
6 7 8 9 10
*/