// Author: JustKitkat
// Status: WIP

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// #define int long long
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
vi p,rankk,setSize;
int numSets;

int findSet(int i){return(p[i]==i)?i:(p[i]=findSet(p[i]));}
bool isSameSet(int i,int j){return findSet(i)==findSet(j);}
int numDisjointSets(){return numSets;}
int sizeOfSet(int i){return setSize[findSet(i)];}

void unionSet(int i, int j){
	if(isSameSet(i,j))return;
	int x = findSet(i),y=findSet(j);
	if(rankk[x]>rankk[y])swap(x,y);
	p[x]=y;
	if(rankk[x]==rankk[y])++rankk[y];
	setSize[y]+=setSize[x];
	--numSets;
}
vii adj[500'005];
vi ans;
void dfs(int v,int u){
    for(auto &x:adj[v])
        if(x.F!=u){
            ans[x.F]=min(ans[x.F],x.S);
            dfs(x.first,v);
        }
}
inline int readInt(){
    int x=0;
    char ch=getchar();
    bool s=1;
    while(ch<'0'||ch>'9'){if(ch=='-')s=0;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return s?x:-1;
}

void solve(int tc){
    n=readInt();
    m=readInt();
    q=readInt();
	int N=n+5;
	p.assign(N, 0);FOR(0,N)p[i]=i;
	rankk.assign(N, 0);
	setSize.assign(N,1);
	numSets=N;
    vector<vi>edges(m,vi(3));
	ans.resize(n+5,1e9);
    for(auto &x:edges){
        x[1]=readInt();
        x[2]=readInt();
        x[0]=readInt();
    }
    sort(all(edges),greater<vi>());
    for(auto &x:edges){
        if(!isSameSet(x[1],x[2]))
            adj[x[1]].pb({x[2],x[0]}),
            adj[x[2]].pb({x[1],x[0]}),
        	unionSet(x[1],x[2]);
    }
    dfs(1,-1);
    while(q--){
        int x=readInt();cout<<ans[x]<<el;
    }
    
}

/*
4 4 2
1 2 10
1 3 30
2 4 20
3 4 5
3
4
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
