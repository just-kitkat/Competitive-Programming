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
#define FOR(a,b) for(int i=a;i<b;++i)
#define DFOR(a,b) for(int i=a;i>=b;--i)
#define JFOR(a,b) for(int j=a;j<b;++j)
#define DJFOR(a,b) for(int j=a;j>=b;--j)
#define show(x) cerr << #x << " is " << x << endl;
#define show2(x,y) cerr << #x << " is " << x << " " << #y << " is " << y << endl;
#define show3(x,y,z) cerr << #x << " is " << x << " " << #y << " is " << y << " " << #z << " is " << z << endl;
#define show_vec(a) { for(auto &x:a)cerr<<x<<' '; cerr<<endl; }
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
const ll INF = 1e15;
const ll MOD = 1e9+7;
const double PI = acos(-1);
const auto BEG = std::chrono::high_resolution_clock::now(); //Begining of the program
#define tii tuple<int,int,int,int>

tii bound(vii &a, ii ignore){
    int mleft=1e9+5, mright=-1, mup=1e9+5, mdown=-1, cnt=0;
    for(auto &x:a){
        if(cnt==0 and (x.F==ignore.F or x.S==ignore.S)){cnt++; continue;}
        mleft=min(mleft,x.S);
        mright=max(mright,x.S);
        mup=min(mup,x.F);
        mdown=max(mdown,x.F);
    }
    return tii(mleft,mright,mup,mdown);
}

ll n=0, m=0, k=0, q=0;
void solve(int tc){
    cin>>n;
    vii a(n);
    for(auto &x:a)cin>>x.F>>x.S;
    if(n==1){cout<<1<<el;return;}
    tii b=bound(a,{-1,-1});
    vii ignore={{-1,get<0>(b)}, {-1,get<1>(b)}, {get<2>(b),-1}, {get<3>(b),-1}};
    int ans=(abs(get<0>(b)-get<1>(b))+1) * (abs(get<2>(b)-get<3>(b))+1);
    // show(ans);
    // show2(get<0>(b),get<1>(b));
    // show2(get<2>(b),get<3>(b));
    // for(auto &x:ignore)show2(x.F,x.S);
    for(auto &x:ignore){
        tii b=bound(a,x);
        int area=(abs(get<0>(b)-get<1>(b))+1) * (abs(get<2>(b)-get<3>(b))+1);
        // show(area);
        if(area >= n)ans=min(ans,area);
        else ans=min(ans,area+min((abs(get<0>(b)-get<1>(b))+1), (abs(get<2>(b)-get<3>(b))+1)));
    }
    cout<<ans<<el;
    
}

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
