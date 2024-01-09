// Author: JustKitkat
// Status: WIP

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ar array
#define ll long long
#define ld long double

#define __time__ { auto duration = chrono::duration<double>( /* Show runtime */ \
chrono::high_resolution_clock::now() - BEG); cout<<"Time: "<<duration.count()<<endl;}
#define __log__ { FILE* file = freopen("../../Testcases/test.out", "w", stdout); }
#define __input__ { FILE* file = freopen("../../Testcases/test.in", "r", stdin); }

const int MAX_N = 1e5 + 5;
const ll INF = 1e9;
const double PI = acos(-1);
const auto BEG = std::chrono::high_resolution_clock::now(); //Begining of the program


void solve(int tc){
    int n,q;
    cin>>n>>q;
    
    vector<ll>h,y,fin;
    unordered_map<ll,ll>m;
    ll mx=0;
    ll mmmmm=((ll)n*n+n)/2;
    for(int i=0;i<n;i++){int t;cin>>t;h.push_back(t);if(t>mx)mx=t;}
    for(int i=0;i<q;i++){int t;cin>>t;y.push_back(t);}
    for(auto x:y){
        if (mx<=x){cout<<mmmmm<<endl;continue;}
        else if(m[x]){cout<<m[x]<<endl;continue;}
        int below_alt=0;
        ll ans=0;
        for(int i=0;i<n;i++){
            if(h[i]<=x)below_alt++;
            else{
                if(below_alt){
                    ans+=(((ll)below_alt*below_alt)+below_alt)/2;
                    below_alt=0;
                }
            }
        }
        ans+=(((ll)below_alt*below_alt)+below_alt)/2;
        cout<<ans<<endl;
        m[x]=ans;
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

 //   __log__ // Redirect output to test.out
  //  __input__ // Read test.in for input

    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }

    //__time__ //Runtime
}