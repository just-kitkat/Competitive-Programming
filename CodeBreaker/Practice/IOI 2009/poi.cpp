// Author: JustKitkat
// Status: WIP

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
#define show(x) cerr << #x << " is " << x << endl;
#define show2(x,y) cerr << #x << " is " << x << " " << #y << " is " << y << endl;
#define show3(x,y,z) cerr << #x << " is " << x << " " << #y << " is " << y << " " << #z << " is " << z << endl;
#define discretize(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());

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
    int n,t,p;
    cin>>n>>t>>p;
    vector<vi> a(n,vi(t));
    vi solves(t);
    vector<vi> b(n,vi(3));
    FOR(0,n){
        JFOR(0,t){
            bool x;cin>>x;
            a[i][j]=x;
            solves[j]+=x;
        }
        b[i][2]=i+1;
    }
    // FOR(0,n)JFOR(0,t)cout<<a[i][j]<<(j==t-1?'\n':' ');
    // for(auto x:solves)cout<<x<<' ';cout<<el;
    FOR(0,n){
        int solved=0;
        JFOR(0,t){
            b[i][0]+=(n-solves[j])*a[i][j];
            solved+=a[i][j];
        }
        b[i][1]=solved;
    }
    sort(all(b), [](vi l, vi r){
        if(l[0]!=r[0])return l[0]<r[0];
        else if(l[1]!=r[1])return l[1]<r[1];
        else return l[2]>r[2];
    });
    int r=n;
    // FOR(0,n)JFOR(0,3)cout<<b[i][j]<<(j==2?'\n':' ');
    for(auto x:b){
        if(x[2]==p)cout<<x[0]<<' '<<r<<el;
        r--;
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //__output__ // Redirect output to test.out
    //__input__ // Read test.in for input

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }

    //__time__ //Runtime
}
// Note: int64_t for exactly 64 bit signed int