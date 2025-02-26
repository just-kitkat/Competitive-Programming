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
void solve(int tc){
    cin>>n>>m>>k;
    int a,b,c;
    cin>>a>>b>>c; // normal, express, semiexpress
    int t;
    cin>>t;
    vi s(m);
    for(auto &x:s)cin>>x;
    sort(all(s));
    // show_vec(s);
    vi result;
    int need=k-m;
    // show(need);
    int ans=0;
    FOR(0,s.size()-1){ // iterate all express trains
        int cost=s[i]*b-b;
        if(cost>t)break;
        ans++; // you are able to reach current station
        // check how many can you go via normal train
        int normal=min(s[i+1]-s[i]-1,(t-cost)/a);
        // show(normal);
        // if(s[i]+normal>=s[i+1]){
        //     ans+=s[i+1]-s[i];
        //     continue; // can get to next express using normal
        // }
        ans+=normal;
        
        // now try to use semiexpress nonsense
        int cur=s[i]+normal+1; // you start from cur+1 to s[i+1]
        cost+=normal*c+c; // travel using semiexpress
        // if a semiexpress is placed at cur, how far can you go
        int cnt=0;
        while(cost<=t and cur<s[i+1]){
            // show("e");
            // show3(cur,normal,cost);
            normal=min(s[i+1]-cur,(t-cost)/a+1);
            if(normal<=0)break;
            result.pb(normal);
            cur+=normal;
            cost+=normal*c;
            cnt++;
            if(cnt>=need)break;
        }
        // show(ans);
    }
    ans+=(n-1)*b<=t;
    sort(all(result));
    while(need-- and result.size())ans+=result.back(),result.pop_back();
    cout<<ans-1;  // exclude station 1
    
}

/*

12 3 4
10 1 2
30
1
11
12
           v       v     v
1 2  3  4  5 6  7  8  9  10 11 12
0 10 20 30 8 18 28 14 24 18 10 20


x       v     x     v  v  x 
1 2  3  4  5  6  7  8  9  10
0 10 20 15 25 15 25 25 30 35

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
