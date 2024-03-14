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
    int n,m;
    cin>>n>>m;
    ll mm=LLONG_MIN;
    vector<vll> a(n,vll(m)),prefi(n,vll(m)),sufi(n,vll(m)),prefj(n,vll(m)),sufj(n,vll(m));
    FOR(0,n)JFOR(0,m){cin>>a[i][j];mm=max(mm,a[i][j]);}
    //pref
    FOR(0,n){ll sum=0,p=0;JFOR(0,m){
        sum+=a[i][j];
        if(j==0)prefi[i][j]=max(0LL,a[i][j]);
        else prefi[i][j]=max({sum,0LL,p+a[i][j]});
        p=max(0LL,p+a[i][j]);}
    }
    JFOR(0,m){ll sum=0,p=0;FOR(0,n){
        sum+=a[i][j];
        if(i==0)prefj[i][j]=max(0LL,a[i][j]);
        else prefj[i][j]=max({sum,0LL,p+a[i][j]});
        p=max(0LL,p+a[i][j]);}
    }
    //suf
    FOR(0,n){ll sum=0,p=0;DJFOR(m-1,0){
        sum+=a[i][j];
        if(j==m-1)sufi[i][j]=max(0LL,a[i][j]);
        else sufi[i][j]=max({sum,0LL,p+a[i][j]});
        p=max(0LL,p+a[i][j]);}
    }
    JFOR(0,m){ll sum=0,p=0;DFOR(n-1,0){
        sum+=a[i][j];
        if(i==n-1)sufj[i][j]=max(0LL,a[i][j]);
        else sufj[i][j]=max({sum,0LL,p+a[i][j]});
        p=max(0LL,p+a[i][j]);}
    }
    // cout<<"DEBUG"<<el;
    // cout<<"PREFI"<<el;
    // for(auto x:prefi){for(auto s:x)cout<<s<<' ';cout<<el;}
    // cout<<"PREFJ"<<el;
    // for(auto x:prefj){for(auto s:x)cout<<s<<' ';cout<<el;}
    // cout<<"SUFI"<<el;
    // for(auto x:sufi){for(auto s:x)cout<<s<<' ';cout<<el;}
    // cout<<"sufj"<<el;
    // for(auto x:sufj){for(auto s:x)cout<<s<<' ';cout<<el;}
    ll ans=0;
    FOR(1,n-1){
        JFOR(1,m-1){
            ans=max(
                ans,
                max(prefi[i][j-1],sufi[i][j+1])
                +max(prefj[i-1][j],sufj[i+1][j])
                +a[i][j]
            );
        }
    }
    //check 4 corners
    if(n>1&&m>1){
        FOR(1,n-1){
            JFOR(1,m-1){
                ans=max(
                    ans,
                    max(prefi[i][j-1],sufi[i][j+1])
                    +max(prefj[i-1][j],sufj[i+1][j])
                    +a[i][j]
                );
            }
        }
        ans=max({
            ans,
            sufi[0][1]+sufj[1][0]+a[0][0],
            prefi[0][m-2]+sufj[1][m-1]+a[0][m-1],
            sufi[n-1][1]+prefj[n-2][0]+a[n-1][0],
            prefi[n-1][m-2]+prefj[n-2][m-1]+a[n-1][m-1],
        });
    }else{
        FOR(0,n){
            JFOR(0,m){
                ans=max(
                    ans,
                    max(prefi[i][j],sufi[i][j])
                    +max(prefj[i][j],sufj[i][j])
                    -abs(a[i][j])
                );
            }
        }
    }
    if(ans<=0)cout<<mm<<el;
    else cout<<ans<<el;
/*
3 3
1 -5 -5
1 -5 -5
-1 1 1
*/
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //__output__ // Redirect output to test.out
    //__input__ // Read test.in for input

    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }

    //__time__ //Runtime
}
// Note: int64_t for exactly 64 bit signed int