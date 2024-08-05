// Author: JustKitkat
// Status: WIP

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

#define __time__ { auto duration = chrono::duration<double>( /* Show runtime */ \
chrono::high_resolution_clock::now() - BEG); cout<<"Time: "<<duration.count()<<endl;}
#define __output__ { FILE* file = freopen("../../../Testcases/test.out", "w", stdout); }
#define __input__ { FILE* file = freopen("../../../Testcases/test.in", "r", stdin); }

// PBDS -> initialise using `ordered_set s;` -> change to greater<int> for reversed order.
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
//#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAX_N = 1e5 + 5;
const ll INF = 1e9;
const double PI = acos(-1);
const auto BEG = std::chrono::high_resolution_clock::now(); //Begining of the program

umap<int,vi>adj;
vi vis(300005);
vi subtree;
ii deepest = {0,0};
void dfs(int u, int depth, bool first=0){
    if(vis[u] && !first)return; vis[u]=1;
    if(!first)subtree.pb(u);
    if(depth>deepest.S) deepest = {u, depth};
    for(auto v:adj[u]) if(!vis[v]) dfs(v, depth+1, 0);
}

vi path;
int diameter_dfs(int u, int depth, int lowest_depth){
    if(vis[u])return 0; vis[u]=1;
    if(depth == lowest_depth){
        path.pb(u);
        return u;
    }
    for(auto v:adj[u]) 
        if(!vis[v]){
            int c = diameter_dfs(v, depth+1, lowest_depth);
            if(c!=0)
                path.pb(u);
                return u;
        }
    return 0;
}

ll n=0, m=0, k=0, q=0;
void solve(int tc){
    cin>>n;
    FOR(0,n-1){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // find diameter
    dfs(1, 0, 0);
    int node1 = deepest.F;
    FOR(1,n+1)vis[i]=0;
    deepest = {0, 0};

    dfs(node1, 0, 0);
    int node2 = deepest.F, depth = deepest.S;
    // show2(node1,node2);
    FOR(1,n+1)vis[i]=0;

    diameter_dfs(node1, 0, depth);
    show_vec(path); // path of diameter

    // for all nodes on diameter, find diameter of subtree
    int max_diameter = 0;
    FOR(1,n+1)vis[i]=0;
    for(auto &x: path)vis[x]=1; // set nodes in path to visited
    umap<int,int> lowest_depth;
    FOR(0,(int)path.size()){
        deepest = {0, 0};
        dfs(path[i],0,1);
        lowest_depth[deepest.F]=deepest.S;
        // deepest = {0, 0};
        // subtree.clear();
        // dfs(path[i], 0, 1);
        // int node1 = deepest.F;
        // for(auto &x: subtree)vis[x]=0;
        
        // dfs(node1, 0, 1);
        // show(deepest.S);
        // max_diameter = max(max_diameter, deepest.S);
    }
    cout<<depth + max_diameter;
}

signed main(){
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
