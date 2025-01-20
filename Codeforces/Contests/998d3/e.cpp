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

ll n=0, m=0, k=0, q=0;
map<int,vi>adj1,adj2;


void solve(int tc){
    int m1,m2;
    cin>>n>>m1>>m2;
    UnionFind uf1(n+5);
    UnionFind uf2(n+5);
    vector<vi> e1,e2;
    FOR(0,m1){
        int u,v;
        cin>>u>>v;
        // uf1.unionSet(u,v);
        adj1[u].pb(v);
        adj1[v].pb(u);
        e1.pb({u,v,0});
    }
    FOR(0,m2){
        int u,v;
        cin>>u>>v;
        uf2.unionSet(u,v);
        adj2[u].pb(v);
        adj2[v].pb(u);
        e2.pb({u,v,0});
    }

    map<int,vi> p1,p2;
    FOR(1,n+1){
        p1[uf1.findSet(i)].pb(i);
        p2[uf2.findSet(i)].pb(i);
    }
    int ans=0;
    // remove
    for(auto &x:e1){
        if(!uf2.isSameSet(x[0],x[1]))ans++,x[2]=1;
    }
    for(auto &x:e1){
        if(x[2]==1)continue;
        uf1.unionSet(x[0],x[1]);
    }
    // add
    for(auto &x:e2){
        if(!uf1.isSameSet(x[0],x[1]))ans++,uf1.unionSet(x[0],x[1]);
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
