// Author: JustKitkat
// Status: WIP

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;

// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define int long long
#define el "\n"
#define arr array
#define ll long long
#define ld long double
#define ii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vii vector<ii>
#define vllll vector<pll>
#define umap unordered_map
#define uset unordered_set
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(a) (a).begin(), (a).end()
#define FOR(a,b) for(auto i=a;i<b;++i)
#define ZFOR(a,b) for(auto z=a;z<b;++z)
#define DFOR(a,b) for(auto i=a;i>=b;--i)
#define JFOR(a,b) for(auto j=a;j<b;++j)
#define DJFOR(a,b) for(auto j=a;j>=b;--j)
#define show(x) cerr << #x << " is " << x << endl;
#define show2(x,y) cerr << #x << " is " << x << " " << #y << " is " << y << endl;
#define show3(x,y,z) cerr << #x << " is " << x << " " << #y << " is " << y << " " << #z << " is " << z << endl;
#define show_vec(a) for(auto &x:a)cerr<<x<<' ';cerr<<endl;
#define discretize(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

#define __time__ { auto duration = chrono::duration<double>( /* Show runtime */ \
chrono::high_resolution_clock::now() - BEG); cout<<"Time: "<<duration.count()<<endl;}

// PBDS -> initialise using `ordered_set s;` -> change to greater<int> for reversed order.
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// #define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAX_N = 1e5 + 5;
const ll INF = 1e9;
const ll MOD = 1e9+7;
const double PI = acos(-1);
const auto BEG = std::chrono::high_resolution_clock::now(); //Begining of the program
int a[205][205];
ii dp[205][205];
ll n=0, m=0, k=0, q=0;
void solve(int tc){
    // min cost kx+y
    // let dp[i][j] be min cost 
    // dp[i][j] = {min_cost, number taken}

    cin>>n>>m>>k;
    FOR(0,n)JFOR(0,m)cin>>a[i][j],dp[i][j]={LLONG_MAX,LLONG_MAX};
    vector<vi>pref(n+5,vi(m+5,0));
    FOR(0,n)JFOR(0,m)pref[i][j+1]=pref[i][j]+a[i][j];
    FOR(0,n){
        JFOR(0,m){
            ii best={LLONG_MAX,LLONG_MAX};
            if(i==0 and j==0){
                show("in");
                ZFOR(0,m){
                    best=min(best,{k*z+a[0][z],z});
                    show2(z,a[0][z]);
                }
                dp[i][j]=best;
            }else if(i==0){
                ZFOR(0,m)best=min(
                    best,
                    // dp[i][j-1].S is ops done so far
                    {
                        k*((z-dp[i][j-1].S+m)%m)+
                        pref[0][z+dp[i][j-1].S+1]-pref[0][z],
                        k*((z-dp[i][j-1].S+m)%m)
                    });
                dp[i][j]=best;
            }else if(j==0){
                ii bestvert={LLONG_MAX,LLONG_MAX};
                ZFOR(0,m){
                    int op=(z-j+m)%m;
                    bestvert=min(bestvert,{dp[i-1][j].F+k*op+a[i-1][z],op});
                }
                dp[i][j]=bestvert;
            }else{
                ZFOR(0,m)best=min(
                    best,
                    // dp[i][j-1].S is ops done so far
                    {
                        k*((z-dp[i][j-1].S+m)%m)+
                        pref[0][z+dp[i][j-1].S+1]-pref[0][z],
                        k*((z-dp[i][j-1].S+m)%m)
                    });
                ii bestvert={LLONG_MAX,LLONG_MAX};
                ZFOR(0,m){
                    int op=(z-dp[i][j-1].S+m)%m;
                    bestvert=min(bestvert,{dp[i-1][j].F+k*op+a[i-1][z],op});
                }
                dp[i][j]=min(best,bestvert);
            }
            show2(i,j);
            show2(dp[i][j].F,dp[i][j].S);
        }
    }
    cout<<dp[n-1][m-1].F<<el;
    
}
/*
1
3 3 100
3 4 9
5 2 4
0 101 101
*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // freopen("out", "w", stdout);
    // freopen("in", "r", stdin);

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }

    //__time__ //Runtime
}
