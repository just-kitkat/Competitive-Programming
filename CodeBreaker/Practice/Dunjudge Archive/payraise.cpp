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
int N=1;
int fw[1000005]={0}, fw2[1000005]={0};
void update(int x, int y, int v) { //inclusive
    for (int tx=x; tx < N; tx += tx&(-tx)) fw[tx] += v, fw2[tx] -= v*(x-1);
    for (int ty=y+1; ty < N; ty += ty&(-ty)) fw[ty] -= v, fw2[ty] += v*y; 
}
int sum (int x) {
    int res = 0;
    for (int tx=x; tx; tx -= tx&(-tx)) res += fw[tx]*x + fw2[tx];
    return res;
}
int range_sum(int x, int y) { //inclusive
    return sum(y)-sum(x-1);
}
umap<int,vi> adj;
vi pre,endo;
int c=3;
void dfs(int v){
	pre[v]=c++;
	for(auto &x:adj[v]){
		dfs(x);
	}
	endo[v]=c-1;
}

ll n=0, m=0, k=0, q=0;
void solve(int tc){
	cin>>n>>q;
	N=n+5;
	vi p(n),s(n);
	pre.resize(n+5),endo.resize(n+5);
	adj.reserve(1000000);
	FOR(0,n){
		int x;cin>>x;
		adj[x].pb(i);
	}
	dfs(0);
	FOR(0,n){
		int x;cin>>x;
		update(pre[i],pre[i],x);
	}
	while(q--){
		int op;cin>>op;
		if(!op){
			int x,d;
			cin>>x>>d;
			update(pre[x],endo[x],d);
		}else{
			int x;cin>>x;
			cout<<range_sum(pre[x],pre[x])<<el;
		}
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
