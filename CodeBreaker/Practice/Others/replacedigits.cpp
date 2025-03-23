// Author: JustKitkat
// Status: WIP

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
const ll MOD = 998244353;
const double PI = acos(-1);
const auto BEG = std::chrono::high_resolution_clock::now(); //Begining of the program

ll n=0, m=0, k=0, q=0;
ll qexp (ll b, ll e) { //quick exponentiation (see below)
    if (e == 0) return 1;
    if (e == 1) return b%MOD;
    ll h = qexp(b, e/2);
    h *= h;
    h %= MOD;
    if (e%2 == 0) return h;
    return (h*b)%MOD;
}
vector<vi> geepee(10,vi(200005));
int gp(int digit, int startlen, int endlen){
    // show3(digit, startlen, endlen);
    return (geepee[digit][endlen] - geepee[digit][startlen-1] + MOD)%MOD;
}

struct node3 {
    int s, e;
    ll mn, mx, sum;
    bool lset;
    ll add_val, set_val;
    node3 *l, *r;
    node3 (int _s, int _e, int A[] = NULL): s(_s), e(_e), mn(0), mx(0), sum(0), lset(0), add_val(0), set_val(0), l(NULL), r(NULL) {
        if (A == NULL) return;
        if (s == e) mn = mx = sum = A[s];
        else {
            l = new node3(s, (s+e)>>1, A), r = new node3((s+e+2)>>1, e, A);
            combine();
        }
    }
    void create_children() {
        if (s == e) return;
        if (l != NULL) return;
        int m = (s+e)>>1;
        l = new node3(s, m);
        r = new node3(m+1, e);
    }
    void self_set(ll v) {
        lset = 1;
        mn = mx = set_val = v;
        sum = gp(v, n-e+1, n-s+1);
    }
    void lazy_propagate() {
        if (s == e) return;
        if (lset) {
            l->self_set(set_val), r->self_set(set_val);
            lset = set_val = 0;
        }   
    }
    void combine() {
        if (l == NULL) return;
        sum = (l->sum + r->sum)%MOD;
        mn = min(l->mn, r->mn);
        mx = max(l->mx, r->mx);
    }
    void set(int x, int y, ll v) {
        if (s == x && e == y) { self_set(v); return; }
        int m = (s+e)>>1;
        create_children(); lazy_propagate();
        if (x <= m) l->set(x, min(y, m), v);
        if (y > m) r->set(max(x, m+1), y, v);
        combine();
    }
    ll range_sum(int x, int y) {
        if (s == x && e == y) return sum%MOD;
        // if (l == NULL || lset) return gp(set_val, n-y, n-x)%MOD;
        int m = (s+e)>>1;
        create_children(); // added
        lazy_propagate();
        if (y <= m) return l->range_sum(x, y);
        if (x > m) return r->range_sum(x, y);
        return (l->range_sum(x, m) + r->range_sum(m+1, y))%MOD;
    }
};

void solve(int tc){
    cin>>n>>q;
    node3 *st=new node3(1,n);
    // construct geepeeee
    FOR(1,10){
        JFOR(1,200004){
            geepee[i][j]=(geepee[i][j-1]+(i*qexp(10,j-1))%MOD)%MOD;
        }
    }
    st->set(1,n,1);
    while(q--){
        int l,r,d;
        cin>>l>>r>>d;
        st->set(l,r,d);
        cout<<st->range_sum(1,n)<<el;
    }
    // show(st->range_sum(n,n));
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
