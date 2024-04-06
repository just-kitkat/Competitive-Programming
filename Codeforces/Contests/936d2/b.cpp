// Author: JustKitkat
// Status: AC

#include <bits/stdc++.h>

using namespace std;

#define el "\n"
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
const int m=1e9+7;

void solve(int tc){
    int n;
    int k;cin>>n>>k;
    vi a(n);
    bool all_neg=1;
    pll ls={0,0};
    // pll sum={0,0};
    ll sum=0;
    pll prev={0,0};
    FOR(0,n){
        cin>>a[i];
        // sum.S+=a[i];
        // sum.F+=sum.F/m;
        // sum.S%=m;
        sum+=a[i];
        sum%=m;
        pll c=prev;c.S+=a[i];
        c.F+=c.S/m;
        c.S%=m;
        
        prev=max(mp(0LL,0LL),c);
        ls=max(ls,prev);
        if(a[i]>0)all_neg=0;
    }    
    if(all_neg){cout<<(sum+m)%m<<el;return;}
    //ls longest subarray
    sum-=ls.S;
    sum=(sum+m)%m;
    
    FOR(0,k){
        ls.S*=2;
        ls.S%=m;
    }
    cout<<(sum+ls.S+m)%m<<el;
    /*
9 10
1000000000 1000000000 -1000000000 -1000000000 -1000000000 1000000000 1000000000 1000000000 1000000000

    */
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //__output__ // Redirect output to test.out
    //__input__ // Read test.in for input

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }

    //__time__ //Runtime
}
// Note: int64_t for exactly 64 bit signed int