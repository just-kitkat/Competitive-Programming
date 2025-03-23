// Author: JustKitkat
// Status: AC   

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAX_N = 1e5 + 5;
const ll INF = 1e15;
const ll MOD = 1e9+7;
const double PI = acos(-1);
const auto BEG = std::chrono::high_resolution_clock::now(); //Begining of the program

int n=0, m=0, k=0, q=0;
int ql, qr, t;
struct node{
    int Start, End, Midpoint;
    ordered_multiset se;
    node *l=nullptr, *r=nullptr;

    node(int s, int e){
        Start = s;
        End = e;
        Midpoint = (Start + End)/2;
    }

    void nodes(){
        if(l!=nullptr)return;
        l = new node(Start, Midpoint);
        r = new node(Midpoint + 1, End);
    }

    int query(){
        if(ql <= Start && End <= qr){
            return se.order_of_key(t-1);
        }
        if(End < ql || qr < Start){
            return 0; //LLONG_MAX if taking min and vice versa, use 0 if sum
        }
        nodes();
        return l->query() + r->query();
    }

    void update(int qx, int qv){ 
        if(Start == End){
            se.insert(qv);
            return;
        }
        nodes();
        if(qx <= Midpoint) l->update(qx, qv);
        else r->update(qx, qv);
        se.insert(qv);

    }

};
#define ti tuple<int,int>
#define ti2 tuple<int,int,int,int>
void solve(int tc){
    cin>>n>>q;
    ti a[n];
    for(auto &x:a){cin>>get<0>(x)>>get<1>(x);}
    sort(a,a+n);
    ti2 qq[q];
    int ind=0;
    for(auto &x:qq){cin>>get<0>(x)>>get<1>(x)>>get<2>(x);get<3>(x)=ind++;}
    sort(qq,qq+q,greater<ti2>());
    node *st=new node(0,2e9+5);
    int ans[q];
    int p=n-1;
    for(auto &x:qq){
        while(p>=0 and get<0>(x)<=get<0>(a[p])){
            st->update(get<1>(a[p]),get<0>(a[p])+get<1>(a[p]));
            --p;
        }
        ql=get<1>(x),qr=2e9+5,t=get<2>(x);
        ans[get<3>(x)]=st->query();
    }
    for(auto &x:ans)cout<<x<<el;

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
