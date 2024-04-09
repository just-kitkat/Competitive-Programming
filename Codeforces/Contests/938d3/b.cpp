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
    int n,c,d;
    cin>>n>>c>>d;
    map<int,int> a;
    int mm=INT_MAX;
    FOR(0,n*n){int tmp;cin>>tmp;mm=min(mm,tmp);a[tmp]++;}
    int cur=mm;
    a[cur]--;
    FOR(0,n){
        // cout<<"DEBUG: "<<cur<<el;
        int cc=cur;
        JFOR(1,n){
            cc+=d;
            // cout<<"DEBUG: "<<cc<<", "<<a[cc]<<el;
            a[cc]--;
            if(a[cc]<0){cout<<"NO\n";return;}
        }
        if(i==n-1)break;
        cur+=c;
        a[cur]--;
        if(a[cur]<0){cout<<"NO\n";return;}
    }
    cout<<"YES\n";
    // 3 9 6 5 7 1 10 4 8
    // 1 3 4 5 6 7 8 9 10
    // 1 4 7
    // 3 6 9
    // 5 8 11
    // sort(all(a));
    // for(auto x:a)cout<<x<<' ';cout<<el;
    // if(!(a[1]-a[0]==c&&a[2]-a[1]==d||a[1]-a[0]==d&&a[2]-a[1]==c)){
    //     cout<<"NO\n";
    //     return;
    // }
    // int prev=a[1]-a[0];
    // FOR(1,n*n){
    //     int diff=a[i]-a[i-1];
    //     if(diff!=prev){cout<<"NO\n";return;}
    //     if(prev==d)prev=c;else prev=d;
    // }
    // cout<<"YES\n";
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