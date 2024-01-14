// Author: JustKitkat
// Status: WIP

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define arr array
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

#define __time__ { auto duration = chrono::duration<double>( /* Show runtime */ \
chrono::high_resolution_clock::now() - BEG); cout<<"Time: "<<duration.count()<<endl;}
#define __log__ { FILE* file = freopen("../../../Testcases/test.out", "w", stdout); }
#define __input__ { FILE* file = freopen("../../../Testcases/test.in", "r", stdin); }

const int MAX_N = 1e5 + 5;
const ll INF = 1e9;
const double PI = acos(-1);
const auto BEG = std::chrono::high_resolution_clock::now(); //Begining of the program


void solve(int tc){
    int n,k,x;cin>>n>>k>>x;
    int a[200005];
    int sum=0;
    for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];}
    //int constsum=sum;
    sort(a,a+n);
    int sw=0;
    int ans=INT_MIN;
    for(int i=0;i<x;i++){sw+=a[n-i-1];}
    //cout<<sum<<' '<<sw<<endl;
    for(int i=n-1;i>=max(0,n-k-1);i--){
        //cout<<sum<<' '<<sw<<' '<<k<<endl;
        ans=max(ans,sum-sw*2);
        sum-=a[i];
        sw=sw+(i-x>=0?a[i-x]:0)-a[i];
    }
    if(k>=n)ans=max(0,ans);
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

   // __log__ // Redirect output to test.out
  //  __input__ // Read test.in for input

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }

    //__time__ //Runtime
}