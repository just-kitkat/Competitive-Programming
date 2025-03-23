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
vii emptyy;
ll n=0, m=0, k=0, q=0;
struct node3 {
    int s, e;
    ll mn, mx, sum, fizz, shake; // store sum of fizz and shake
    bool lset;
    ll add_val, set_val, fizzlazy, shakelazy; // store multiplier
    node3 *l, *r;
    node3 (int _s, int _e, vii &A): s(_s), e(_e), mn(0), mx(0), sum(0), lset(0), add_val(0), set_val(0), l(NULL), r(NULL), fizz(0), shake(0), fizzlazy(0), shakelazy(0) {
        if (A.empty()) return;
        if (s == e) sum = A[s-1].F*A[s-1].S, fizz=A[s-1].F, shake=A[s-1].S;
        else {
            l = new node3(s, (s+e)>>1, A), r = new node3((s+e+2)>>1, e, A);
            combine();
        }
    }
    void create_children() {
        if (s == e) return;
        if (l != NULL) return;
        int m = (s+e)>>1;
        l = new node3(s, m, emptyy);
        r = new node3(m+1, e, emptyy);
    }
    void self_add(ll op, ll v) {
        if(op==0){ // fizz
            fizzlazy+=v;
            fizz+=v*(e-s+1);
            sum+=v*shake;
        }else{ // shake
            shakelazy+=v;
            shake+=v*(e-s+1);
            sum+=v*fizz;
        }
    }
    void lazy_propagate() {
        if (s == e) return;
        if (fizzlazy != 0) {
            l->self_add(0, fizzlazy), r->self_add(0, fizzlazy);
            fizzlazy=0;
        }
        if(shakelazy != 0){
            l->self_add(1,shakelazy), r->self_add(1,shakelazy);
            shakelazy=0;
        }
    }
    void combine() {
        if (l == NULL) return;
        fizz=l->fizz+r->fizz;
        shake=l->shake+r->shake;
        sum=l->sum+r->sum;
    }
    void addfizz(int x, int y, ll v) {
        if (s == x && e == y) { self_add(0, v); return; }
        int m = (s+e)>>1;
        create_children(); lazy_propagate();
        if (x <= m) l->addfizz(x, min(y, m), v);
        if (y > m) r->addfizz(max(x, m+1), y, v);
        combine();
    }
    void addshake(int x, int y, ll v) {
        if (s == x && e == y) { self_add(1, v); return; }
        int m = (s+e)>>1;
        create_children(); lazy_propagate();
        if (x <= m) l->addshake(x, min(y, m), v);
        if (y > m) r->addshake(max(x, m+1), y, v);
        combine();
    }
    ll range_sum(int x, int y) {
        if (s == x && e == y) return sum;
        if (l == NULL || lset) return (sum / (e-s+1)) * (y-x+1);
        int m = (s+e)>>1;
        lazy_propagate();
        if (y <= m) return l->range_sum(x, y);
        if (x > m) return r->range_sum(x, y);
        return l->range_sum(x, m) + r->range_sum(m+1, y);
    }
};
void solve(int tc){
    cin>>n>>q;
    vii a(n);
    for(auto &x:a)cin>>x.F;
    for(auto &x:a)cin>>x.S;
    node3 *ST[2]={new node3(1,n,a), new node3(1,n,a)};
    vi prefmult(n+1),preff(n+1),prefs(n+1);
    FOR(0,n)
        prefmult[i+1]=prefmult[i]+a[i].F*a[i].S,
        preff[i+1]=preff[i]+a[i].F,
        prefs[i+1]=prefs[i]+a[i].S;
    while(q--){
        int op,l,r,k;
        cin>>op>>l>>r;
        if(op!=3)cin>>k;
        if(op==1){ // increase F by k
            ST[0]->addfizz(l,r,k);
        }else if(op==2){ // increase S by k
            ST[0]->addshake(l,r,k);
        }else{ // query L to R
            int total=ST[0]->range_sum(l,r);
            cout<<total<<el;
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
