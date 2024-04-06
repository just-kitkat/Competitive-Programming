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

vi d(int n) 
{ 
    vi res;
    // Note that this loop runs till square root 
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            // divisors are equal
            if (n/i == i) 
                // cout <<" "<< i;
                res.pb(i); 
  
            else // Otherwise both
                res.pb(i);
                res.pb(n/i);
                // cout << " "<< i << " " << n/i; 
        } 
    } 
    return res;
} 
  
void solve(int tc){
    int n;
    cin>>n;
    string l;
    cin>>l;

    vi a=d(n);
    sort(all(a));
    int ans=n;
    for(auto x:a){
        int inval=0;
        string s=l.substr(0,x);
        string r="";
        FOR(0,n/x)r+=s;
        bool f=1;
        FOR(0,n){
            if(r[i]!=l[i])inval++;
            if(inval>1){f=0;}
        }
        if(f){ans=min(ans,x);break;}
    }
    for(auto x:a){
        if(x>n/2)break;
        int inval=0;
        string s=l.substr(x,x);
        string r="";
        FOR(0,n/x)r+=s;
        bool f=1;
        FOR(0,n){
            if(r[i]!=l[i])inval++;
            if(inval>1){f=0;}
        }
        if(f){ans=min(ans,x);break;}
    }
    cout<<ans<<el;
    
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