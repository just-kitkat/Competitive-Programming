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

ll n=0, m=0, k=0, q=0;
vii initadj[300'005];
vi depths;
umap<int,ii> adj;
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
        if(depths[x]<depths[y])swap(x,y);
        p[x]=y;
        // if(rank[x]==rank[y])++rank[y];
        setSize[y]+=setSize[x];
        --numSets;
    }
};
void dfs(int v, int u, int depth){
    depths[v]=depth;
    for(auto &x:initadj[v]){
        if(x.F==u)continue;
        adj[x.F]={v,x.S};
        dfs(x.F,v,depth+1);
    }
}

bool cmp(vi l, vi r){
    return l.back() < r.back();
}

void solve(int tc){
    int e;
    cin>>n>>e;
    vii edges(e);
    UnionFind uf(300'005);
    set<int>tree;
    depths.resize(n+5);
    vi ans(e);
    for(auto &x:edges){
        cin>>x.F>>x.S;
        x.F--,x.S--;
    }
    FOR(0,n-1){
        int ind;cin>>ind;ind--;
        int u=edges[ind].F, v=edges[ind].S;
        tree.insert(ind);
        initadj[u].pb({v,ind});
        initadj[v].pb({u,ind});
    }
    dfs(0,-1,0);
    int cnt=1, ind=-1;
    // for(auto &x:adj)cout<<x.F<<":"<<x.S.F<<","<<x.S.S<<el;
    // exit(0);
    // for(auto &x:tree)cout<<x.F<<","<<x.S<<"  ";cout<<el;
    for(auto &x:edges){
        ind++;
        if(tree.count(ind)){
            if(ans[ind]==0){
                ans[ind]=cnt;
                cnt++;
                uf.unionSet(x.F,x.S);
            }
            continue;
        }
        int u=x.F, v=x.S;
        vector<vi> use;
        while(u!=v){
            while(depths[u]>depths[v]){
                if(uf.findSet(u)!=u){
                    u=uf.findSet(u);
                    continue;
                }
                use.pb({u,adj[u].F,adj[u].S}),
                u=adj[u].F;
            }
            if(u==v)break;
            while(depths[u]<depths[v]){
                if(uf.findSet(v)!=v){
                    v=uf.findSet(v);
                    continue;
                }
                use.pb({v,adj[v].F,adj[v].S}),
                v=adj[v].F;
            }
            if(u==v)break;
            if(depths[u]==depths[v]){
                if(uf.findSet(u)!=u or uf.findSet(v)!=v){
                    u=uf.findSet(u), v=uf.findSet(v);
                    continue;
                }
                use.pb({u,adj[u].F,adj[u].S}),
                use.pb({v,adj[v].F,adj[v].S}),
                u=adj[u].F,
                v=adj[v].F;
            }
        }
        sort(all(use), cmp);
        for(auto &x:use){
            // show2(cnt,ind);
            // show_vec(x);
            if(ans[x[2]]==0 and !uf.isSameSet(x[0],x[1])){
                ans[x[2]]=cnt,cnt++;
                uf.unionSet(x[0],x[1]);
            }
        }
        if(ans[ind]==0){
            ans[ind]=cnt;
            cnt++;
        }
    }
    int inc=0;
    // mex??
    set<int>ss;
    // show_vec(ans);
    FOR(1,300'005)ss.insert(i);
    FOR(0,e){
        if(ans[i]==0){
            ans[i]=*ss.begin();
            ss.erase(*ss.begin());
            inc++;
        }
        else{
            ans[i]+=inc;
            ss.erase(ans[i]);
        }
    }
    assert(*min_element(all(ans))>0);
    for(auto &x:ans)cout<<x<<' ';
    
}

/*

5 6
1 2
2 5
1 3
2 4
3 4
3 5
1 3 4 6

 1
2 3
4 5

4 5
2 3
0 1
1 2
0 2
0 3
2 4 5
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
