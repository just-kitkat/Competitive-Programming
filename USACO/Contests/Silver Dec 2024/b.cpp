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
#define DFOR(a,b) for(auto i=a;i>=b;--i)
#define JFOR(a,b) for(auto j=a;j<b;++j)
#define DJFOR(a,b) for(auto j=a;j>=b;--j)
#define show(x) cout << #x << " is " << x << el;
#define show2(x,y) cout << #x << " is " << x << " " << #y << " is " << y << el;
#define show3(x,y,z) cout << #x << " is " << x << " " << #y << " is " << y << " " << #z << " is " << z << el;
#define show_vec(a) for(auto &x:a)cerr<<x<<' ';cerr<<el;
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

ll n=0, m=0, k=0, q=0;
void solve(int tc){
    cin>>n>>k;
    vi a(n);
    for(auto &x:a){cin>>x;x+=INF;}
    sort(all(a));
    vi d=a;
    vector<vi>ranges(k);
    while(k--){
        int l,r,t;
        cin>>l>>r>>t;
        r+=INF,l+=INF;
        auto itl=lower_bound(all(a),l);
        auto itr=upper_bound(all(a),r);
        // if(itl!=a.begin())--itl;
        if(itr!=a.begin())--itr;
        l=*itl,r=*itr;
        ranges[k]={l,r,t};
    }
    discretize(d);
    for(auto &x:a)x=lower_bound(all(d),x)-d.begin();
    for(auto &x:ranges)
        x[0]=lower_bound(all(d),x[0])-d.begin(),
        x[1]=lower_bound(all(d),x[1])-d.begin();
    // show_vec(a);
    // for(auto &x:ranges){show_vec(x);}
    sort(all(ranges));
    int cnt=0;

    FOR(0,n){
        bool take=false;
        for(auto &x:ranges){
            if(x[2]<=0)continue;
            if(x[1]-i+1==x[2])take=true;
            }
        cnt+=take;
        if(take)for(auto &x:ranges)if(i>=x[0] and i<=x[1])x[2]--;
    }
    cout<<n-cnt<<el;
}

/*

1 
3 1
3 10 12
3 112496721 1

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
