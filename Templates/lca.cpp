// Codebreaker: winter
// MST + 2k-decomp + LCA to find max edge

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
const ll INF = 1e9;
const ll MOD = 1e9+7;
const double PI = acos(-1);
const auto BEG = std::chrono::high_resolution_clock::now(); //Begining of the program
class UnionFind{
private:
    vi p,rank,setSize;
    int numSets;
public:
    UnionFind(int N){
        p.assign(N, 0);FOR(0,N)p[i]=i;
        rank.assign(N, 0);
        setSize.assign(N,1);
        numSets=N;
    }

    int findSet(int i){return(p[i]==i)?i:(p[i]=findSet(p[i]));}
    bool isSameSet(int i,int j){return findSet(i)==findSet(j);}
    int numDisjointSets(){return numSets;}
    int sizeOfSet(int i){return setSize[findSet(i)];}
    
    void unionSet(int i, int j){
        if(isSameSet(i,j))return;
        int x = findSet(i),y=findSet(j);
        if(rank[x]>rank[y])swap(x,y);
        p[x]=y;
        if(rank[x]==rank[y])++rank[y];
        setSize[y]+=setSize[x];
        --numSets;
    }
};

umap<int,vii>adj;

ii twok[200005][20]; //preset to -1
int depth[200005]={0};
void dfs(int x, int p, int d) {
	for (int k = 0; k < 19; ++k) {
		if (twok[x][k].F == -1) break;
		twok[x][k+1] = {twok[twok[x][k].F][k].F,max(twok[twok[x][k].F][k].S,twok[x][k].S)};
	}
    depth[x]=d;
    for (ii it:adj[x]) {
		if(it.F == p) continue;
		twok[it.F][0] = {x,it.S};
		dfs(it.F,x,d+1);
	}
}

ii kpar(int v, int k){
    int res=0;
    FOR(0,20) if(v==-1)break;else if(k&(1<<i)) res=max(res,twok[v][i].S), v = twok[v][i].F;
    return {v,res};
}


ii lca(int a,int b){
    if (depth[a] < depth[b]) swap(a,b);
    ii r = kpar(a, depth[a] - depth[b]);
    a=r.F;
    int res=r.S;
    if (a == b) return {a,res}; // edge case where b is an ancestor of a
    for (int k=19;k>=0;k--){
        if (twok[a][k].F != twok[b][k].F){
            res=max({res, twok[a][k].S, twok[b][k].S});
            a = twok[a][k].F; b = twok[b][k].F;
        }
    }
    res=max(res,twok[a][0].S);
    res=max(res,twok[b][0].S);
    return {twok[a][0].F,res};
}


ll n=0, m=0, k=0, q=0;
void solve(int tc){
    cin>>n>>m;
    FOR(0,200005)JFOR(0,20)twok[i][j]={-1,(int)1e18};
    vector<vi> edges;
    FOR(0,m){
        int u,v,w;
        cin>>u>>v>>w;
        edges.pb({w,u,v});
    }
    auto back=edges;
    sort(all(edges));
    UnionFind uf(n+5);
    umap<int, umap<int, int>>ss;
    int total=0;
    for(auto &x:edges){
        if(!uf.isSameSet(x[1],x[2])){
            uf.unionSet(x[1],x[2]);
            total+=x[0];
            adj[x[1]].pb({x[2],x[0]});
            adj[x[2]].pb({x[1],x[0]});
            ss[x[1]][x[2]]=x[0];
            ss[x[2]][x[1]]=x[0];
        }
    }
    dfs(1, -1, 1);
    FOR(0, m){
        int v1=back[i][1],v2=back[i][2];
        ii r=lca(back[i][1],back[i][2]);
        if(ss[v1].count(v2))cout<<total-ss[v1][v2]+back[i][0];
        else cout<<total+back[i][0]-r.S;
        cout<<el;
        // show2(r.F,r.S);
    }

    
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
