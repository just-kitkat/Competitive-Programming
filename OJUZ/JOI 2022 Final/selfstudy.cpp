#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define show3(x,y,z) cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define ld long double
void solve(){//nt n, int m, vector<int>&a, vector<int>&b){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(n);
    for(auto &x:a)cin>>x;
    for(auto &x:b)cin>>x;
    int lo=1,hi=1e18;
    while(lo<hi){
        int mid=(lo+hi+1)/2; // min level is mid
        long double over=0;
        for(int i=0;i<n;++i){
            // try to get a level of >= mid
            int take=0;
            if(a[i]>b[i]){ // if its better to go for the course
                take+=min(m,(mid-1)/a[i] + 1);
            }
            int left=mid-take*a[i];
            if(left>0){
                // use as many b[i] to reach mid
                take+=(left-1)/b[i] + 1;
            }
            // cout<<take<<endl;
            // assert(take>0); // true
            over+=m-take;  // over > 0, m-take <= 0
            // if(over>0)assert(0);
            // assert(m-take<=0); // true
            // assert(over<=0); // false
        }
        // show3(mid,over,lo);
        if(over<0)hi=mid-1;
        else lo=mid;
    }
    cout<<lo;
    // return lo;
}

int bf(int n, int m, vector<int>&a, vector<int>&b){
    // int n,m;
    // cin>>n>>m;
    // vector<int> a(n),b(n);
    // for(auto &x:a)cin>>x;
    // for(auto &x:b)cin>>x;
    int ans=LLONG_MAX;
    for(int i=0;i<n;++i)ans=min(max(a[i],b[i]),ans);
    // cout<<ans;
    return ans;
}

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    // int m=1;
    // for(int n=1;n<4;++n){
    //     cout<<"doing "<<n<<endl;
    //     for(int p=0;p<100000000;++p){
    //         vi a(n),b(n);
    //         for(auto &x:a)x=(rnd()%1'000'000'000+1);
    //         for(auto &x:b)x=(rnd()%1'000'000'000+1);
    //         if(solve(n,m,a,b)!=bf(n,m,a,b)){
    //             cout<<n<<endl;
    //             for(auto &x:a)cout<<x<<' ';cout<<endl;
    //             for(auto &x:b)cout<<x<<' ';cout<<endl;
    //             exit(0);
    //         }
    //     }
    // }
    // int n=2;
    // vi a = {1111, 2111};
    // vi b = {317, 81};
    // solve(n,m,a,b);
    // cout<<endl;
    // bf(n,m,a,b);
    // cout<<"\ndone";

}