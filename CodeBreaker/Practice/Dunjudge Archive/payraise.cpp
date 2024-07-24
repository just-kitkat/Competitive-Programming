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
umap<int,int>m;
umap<int,vi>adj;

const int maxN = 4e6 + 5;

int N, Q;
int a[maxN];

struct node {
	ll val;
	ll lzAdd;
	ll lzSet;
	node(){};
} tree[maxN << 2];

#define lc p << 1
#define rc (p << 1) + 1

inline void pushup(int p) {
	tree[p].val = tree[lc].val + tree[rc].val;
	return;
}

void pushdown(int p, int l, int mid, int r) {
	// lazy: range set
	if (tree[p].lzSet != 0) {
		tree[lc].lzSet = tree[rc].lzSet = tree[p].lzSet;
		tree[lc].val = (mid - l + 1) * tree[p].lzSet;
		tree[rc].val = (r - mid) * tree[p].lzSet;
		tree[lc].lzAdd = tree[rc].lzAdd = 0;
		tree[p].lzSet = 0;
	} else if (tree[p].lzAdd != 0) {  // lazy: range add
		if (tree[lc].lzSet == 0) tree[lc].lzAdd += tree[p].lzAdd;
		else {
			tree[lc].lzSet += tree[p].lzAdd;
			tree[lc].lzAdd = 0;
		}
		if (tree[rc].lzSet == 0) tree[rc].lzAdd += tree[p].lzAdd;
		else {
			tree[rc].lzSet += tree[p].lzAdd;
			tree[rc].lzAdd = 0;
		}
		tree[lc].val += (mid - l + 1) * tree[p].lzAdd;
		tree[rc].val += (r - mid) * tree[p].lzAdd;
		tree[p].lzAdd = 0;
	}
	return;
}

void build(int p, int l, int r) {
	tree[p].lzAdd = tree[p].lzSet = 0;
	if (l == r) {
		tree[p].val = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(lc, l, mid);
	build(rc, mid + 1, r);
	pushup(p);
	return;
}

void add(int p, int l, int r, int a, int b, ll val) {
	if (a > r || b < l) return;
	if (a <= l && r <= b) {
		tree[p].val += (r - l + 1) * val;
		if (tree[p].lzSet == 0) tree[p].lzAdd += val;
		else tree[p].lzSet += val;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(p, l, mid, r);
	add(lc, l, mid, a, b, val);
	add(rc, mid + 1, r, a, b, val);
	pushup(p);
	return;
}

void sset(int p, int l, int r, int a, int b, ll val) {
	if (a > r || b < l) return;
	if (a <= l && r <= b) {
		tree[p].val = (r - l + 1) * val;
		tree[p].lzAdd = 0;
		tree[p].lzSet = val;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(p, l, mid, r);
	sset(lc, l, mid, a, b, val);
	sset(rc, mid + 1, r, a, b, val);
	pushup(p);
	return;
}

ll query(int p, int l, int r, int a, int b) {
	if (a > r || b < l) return 0;
	if (a <= l && r <= b) return tree[p].val;
	int mid = (l + r) >> 1;
	pushdown(p, l, mid, r);
	return query(lc, l, mid, a, b) + query(rc, mid + 1, r, a, b);
}


int vis[1000009]={0};
int subtreesz[1000009];
int dfs(int u, int c){
    if(vis[u])return c;
    vis[u]=1;
    m[u]=c;
    int old=c;
    c++;
    for(auto v:adj[u]){
        if(!vis[v]){
            c = dfs(v, c);
        }
    }
    subtreesz[u]=old-c;
    return c;
}

ll n,q;
void solve(int tc){
    cin>>n>>q;
    N=n;
    vi p(n);FOR(0,n){
        int superior;cin>>superior;
        adj[superior].pb(i);
    }
    vi s(n);FOR(0,n){
        int x;cin>>x;
        sset(1,1,N,i,i,x);
    }
    int c=0;
    FOR(0,n)c=dfs(i,c);

    FOR(0,q){
        int op;cin>>op;
        if(op==0){
            int x,d;cin>>x>>d;
            add(1,1,N,m[x],subtreesz[m[x]],d); //PQRU
        }else{
            int x;cin>>x;
            cout<<query(1,1,N,m[x],m[x])<<el;
        }
    }
    
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
