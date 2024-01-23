// Author: JustKitkat
// Status: WA ( help D: )

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
#define vii vector<pair<int,int>>
#define vllll vector<pair<ll,ll>>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(a) (a).begin(), (a).end()
#define FOR(a,b) for(auto i=a;i<b;++i)
#define DFOR(a,b) for(auto i=a;i>=b;--i)
#define JFOR(a,b) for(auto j=a;j<b;++j)
#define DJFOR(a,b) for(auto j=a;j>=b;--j)

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

#define __time__ { auto duration = chrono::duration<double>( /* Show runtime */ \
chrono::high_resolution_clock::now() - BEG); cout<<"Time: "<<duration.count()<<endl;}
#define __output__ { FILE* file = freopen("../../../Testcases/test.out", "w", stdout); }
#define __input__ { FILE* file = freopen("../../../Testcases/test.in", "r", stdin); }

const int MAX_N = 1e5 + 5;
const ll INF = 1e9;
const double PI = acos(-1);
const auto BEG = std::chrono::high_resolution_clock::now(); //Begining of the program

// sort a, b, c
// a+b>c
// dp, where dp[i]=dp[i-1]+s, where s is the smallest int where s > A[i]-A[i-1]
// or maybe (s*(s-1))/2
// binary search to find s
// for A[i] how many pairs of numbers Axy where x<i follow A[x]+A[y]>A[i] (must be unique)
/*
3 2 1 3
ORI: 1 2 3 3 
ANS: 0 0 0 2

2 5 4 1 2
ORI: 1 2 2 4 5
ANS: 0 0 1 1 3

ORI: 2 2 4 6 10 11
ANS: 0 0 0 0 0  4

ORI: 1 1 1 1 1 1 1
ANS: 0 0 1 3 6 10 15 WRONG
         1 4 9 14 15
*/

void solve(int tc){
    int n;
    cin>>n;
    int t;
    map<int,int>m;
    FOR(0,n){
        cin>>t;m[t]++;
    }
    int ans=0;
    for(auto [k,v]: m){
        if(v>1)ans+=(v-1)*(n-2);
        else if(m[k-1]>1)ans+=(m[k-1])*(m[k-1]-1)/2;
        ans+=v>=3;
    }
    cout<<ans<<endl;
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //__output__ // Redirect output to test.out
    __input__ // Read test.in for input

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }

    //__time__ //Runtime
}