// Author: JustKitkat
// Status: AC

#include <bits/stdc++.h>

using namespace std;

#define el "\n"
#define arr array
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vii vector<pair<int,int>>
#define vllll vector<pair<ll,ll>>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(a) (a).begin(), (a).end()
#define FOR(a,b) for(auto i=a;i<b;++i)
#define DFOR(a,b) for(auto i=a;i>=b;--i)
#define JFOR(a,b) for(auto j=a;j<b;++j)
#define DJFOR(a,b) for(auto j=a;j>=b;--j)

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

#define __time__ { auto duration = chrono::duration<double>( /* Show runtime */ \
chrono::high_resolution_clock::now() - BEG); cout<<"Time: "<<duration.count()<<endl;}
#define __output__ { FILE* file = freopen("../../../Testcases/test.out", "w", stdout); }
#define __input__ { FILE* file = freopen("../../../Testcases/test.in", "r", stdin); }

const int MAX_N = 1e5 + 5;
const ll INF = 1e9;
const double PI = acos(-1);
const auto BEG = std::chrono::high_resolution_clock::now(); //Begining of the program
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define pii pair<int,int>
#define dbg(v)\
    cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

struct node{
	node *left, *right;
	int S, E, val, lazy;
	node(int _s, int _e) : S(_s), E(_e){
			left = right = nullptr;
			val = 0;
			lazy = 0;
	}

	void prop(){
		if(S == E) return;
		int M = (S+E) >> 1;
		if(left == nullptr){
			left = new node(S, M);
			right = new node(M+1, E);
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

void solve(int tc){
    int n, q;
    cin>>n>>q;
    node *st = new node(1,n);

    FOR(0,q){
        int a,b,c,d;
        cin>>a>>b>>c;
        if(a==1){cin>>d;st->upd(b,c,d);}
        else cout<<st->qry(b,c)<<el;
    }
    
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //__output__ // Redirect output to test.out
    //__input__ // Read test.in for input

    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }

    //__time__ //Runtime
}
// Note: int64_t for exactly 64 bit signed int