// Author: JustKitkat
// Status: AC

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
const ll INF = 1'500'000'000;
const ll MOD = 1e9+7;
const double PI = acos(-1);
const auto BEG = std::chrono::high_resolution_clock::now(); //Begining of the program

ll n=0, m=0, k=0, q=0;
vii a;
int memo[5001][5001][2];
int dp(int pos, int left, int last){
    int res=-INF;
    // base case
    if(left<0) return -INF;
    if(pos==0){
        if(last==0){
            if(left>0) return max((ll)0,a[0].S-(n<=1?0:a[0].F*a[1].F));
            else return 0;
        }else{ // if im currently taking
            if(left>0) return a[0].S;
            if(left==0 and n>1) return -a[0].F*a[1].F;
            return 0;
        }
    }
    if(memo[pos][left][last]!=-INF-5)return memo[pos][left][last];

    // already taken
    if(last!=0){
        // take
        if(left>0)res=max(res,dp(pos-1,left-1,1)+a[pos].S);
        // stop taking
        res=max(res,dp(pos-1,left,0)-(pos+1>=n?0:a[pos].F*a[pos+1].F));
    }
    // have not taken
    else{
        // start taking
        if(left>0)res=max(res,
            dp(pos-1,left-1,1)+a[pos].S-(pos+1>=n?0:a[pos+1].F*a[pos].F));
        // continue to not take
        res=max(res,dp(pos-1,left,0));
    }
    return memo[pos][left][last]=res;
}

void solve(int tc){
    cin>>n>>k;
    a.resize(n);
    // fill(&memo[0][0][0],&memo[0][0][0]+5001*5001*2,-INF-5);
    FOR(0,5001)JFOR(0,5001)memo[i][j][0]=-INF-5,memo[i][j][1]=-INF-5;
    for(auto &x:a)cin>>x.F;
    for(auto &x:a)cin>>x.S;
    cout<<max((ll)0,dp(n-1,k,0));
}

/*

5 2
1 9 9 9 2
20 20 20 20 20

3 2
1 1 1
10 1 1

3 1
1 1 1
1 1 1

*/

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // freopen("out", "w", stdout);
    // freopen("in", "r", stdin);

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }

    //__time__ //Runtime
}
