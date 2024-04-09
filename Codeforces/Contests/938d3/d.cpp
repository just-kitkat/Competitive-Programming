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


void solve(int tc){
    int n,m,k;
    cin>>n>>m>>k;
    vi a(n),b(m);
    FOR(0,n)cin>>a[i];
    FOR(0,m)cin>>b[i];
    int positive=0;
    map<int,int>ma,freq;
    for(auto x:b){
        ma[x]=0;
    }
    for(auto x:b)freq[x]++;
    int p1=0,p2=m-1;
    FOR(0,m){
        if(ma.count(a[i])){
            ma[a[i]]++;
            if(ma[a[i]]<=freq[a[i]])positive++;
        }
    }
    int ans=positive>=k;
    while(p2<n-1){
        // cout<<p1<<' '<<p2<<' '<<a[p2+1]<<endl;
        if(ma.count(a[p1])){
            // cout<<"c"<<endl;
            ma[a[p1]]--;
            if(ma[a[p1]]<freq[a[p1]])positive--;
        }
        p1++;
        p2++;
        if(ma.count(a[p2])){
            // cout<<"d"<<endl;
            ma[a[p2]]++;
            if(ma[a[p2]]<=freq[a[p2]])positive++;
        }
        ans+=positive>=k;
    }
    cout<<ans<<el;

}
/*
1
5 7
3 2 1 1 3

1
5 10
1 1 5 1 1
*/

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