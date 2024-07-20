// Author: JustKitkat
// Status: AC

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
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
//#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAX_N = 1e5 + 5;
const ll INF = 1e9;
const double PI = acos(-1);
const auto BEG = std::chrono::high_resolution_clock::now(); //Begining of the program
umap<int,vector<ii>>adj;
int vis[3'000'005]={0};
int city[3'000'005];

class UnionFind{
private:
public:
    vi p,rank,setSize;
    int numSets;
    UnionFind(int N){
        p.assign(N, 0);FOR(0,N)p[i]=i;
        // rank.assign(N, 0);
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
        if(city[x]<city[y])swap(x,y);
        p[x]=y;
        // if(rank[x]==rank[y])++rank[y];
        setSize[y]+=setSize[x];
        --numSets;
    }
};


ll n=0, m=0, k=0, q=0;
void solve(int tc){
    int r;
    cin>>n>>r;
    FOR(0,n)cin>>city[i];
    vector<vi> edges;
    FOR(0,r){
        int u,v,c;
        cin>>u>>v>>c;
        edges.pb({c,u,v});
    }
    sort(all(edges));
    int ans=0;
    auto uf=UnionFind(n+5);
    vector<vi> newedges;
    for(auto x:edges){
        if(uf.isSameSet(x[1],x[2]) or city[uf.findSet(x[1])] < x[0] and x[0] > city[uf.findSet(x[2])]);
        else uf.unionSet(x[1],x[2]),ans+=x[0];
        // show_vec(uf.p);
    }
    uset<int> s;
    FOR(0,n)if(!s.count(uf.findSet(i)))
        ans+=city[uf.findSet(i)],s.insert(uf.findSet(i));
    cout<<ans;
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
