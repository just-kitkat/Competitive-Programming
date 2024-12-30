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
struct node2{
	node2 *left, *right;
	int S, E, val, lazy;
	node2(int _s, int _e) : S(_s), E(_e){
			left = right = nullptr;
			val = 0;
			lazy = 0;
	}

	void prop(){
		if(S == E) return;
		int M = (S+E) >> 1;
		if(left == nullptr){
			left = new node2(S, M);
			right = new node2(M+1, E);
		}
		if(lazy != 0){
			left->val += lazy*(M-S+1);
			left->lazy += lazy;
			right->val += lazy*(E-M);
			right->lazy += lazy;
			lazy = 0;
		}
	}

	int qry(int l, int r){
		if (l > E || r < S) return 0;
		if(l <= S && E <= r) return val;
		prop();
		return left->qry(l, r) + right->qry(l, r);
	}
	
	void upd(int l, int r, int v){
		if(l > E || r < S) return;
		if(l <= S && E <= r){
			val += v*(E-S+1);
			lazy += v;
			return;
		}
		prop();
		left->upd(l, r, v);
		right->upd(l, r, v);
		val = left->val + right->val;
	}
};
ll n=0, m=0, k=0, q=0;
void solve(int tc){
    cin>>n;
    node2 *st = new node2(0, n);
    FOR(0,n){
        int x;cin>>x;
        st->upd(i,i,x);
    }
    cin>>q;
    FOR(0,q){
        int op;
        cin>>op;
        if(op){
            int l,r,v;
            cin>>l>>r>>v;
            st->upd(l,r,v);
        }else{
            int l,r;
            cin>>l>>r;cout<<st->qry(l,r);
        }cout<<el;
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
