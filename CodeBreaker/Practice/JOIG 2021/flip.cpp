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
const ll INF = 2e18;
const ll MOD = 1e9+7;
const double PI = acos(-1);
const auto BEG = std::chrono::high_resolution_clock::now(); //Begining of the program
#define ti tuple<int,int,int>
umap<int,vector<ti>> adj;
vi vis;
ll n=0, m=0, k=0, q=0,l;
// dist[vertex][flip] = weight
void dijkstra(int s, vector<vi> & dist) {
    priority_queue<ti, vector<ti>, greater<ti>> pq;

    pq.push({0, 0, s}); // dist, flip, source
    FOR(0,1005)dist[s][i] = 0;

    while (!pq.empty()) {
        auto x = pq.top();
        int u = get<2>(x), dd = get<0>(x), flip = get<1>(x);
        pq.pop();
        if(dd>dist[u][flip])continue;

        for (auto &x : adj[u]) {
            int v = get<0>(x), weight = get<1>(x), flipCur = get<2>(x);
            if (dist[v][flip+flipCur] > dist[u][flip] + weight && dist[u][flip]+weight<=l && flip+flipCur<=m) {
                FOR(flip+flipCur,1005) {
                    if(dist[v][i]<=dist[u][i-flipCur])break;
                    dist[v][i] = min(dist[v][i], dist[u][i-flipCur] + weight);
                }
                pq.push({dist[v][flip+flipCur], flip+flipCur, v});
            }
        }
    }
}

void solve(int tc){
    cin>>n>>m>>l;
    FOR(0,m){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w,0});
        adj[v].pb({u,w,1});
    }
    vector<vi> dist(1005,vi(1005,(int)1e18));
    dijkstra(1,dist);
    int ans=1e18;
    FOR(0ll,1005ll)if(dist[n][i]<=l)ans=min(ans,i);
    cout<<(ans==(int)1e18?-1:ans);
}

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
