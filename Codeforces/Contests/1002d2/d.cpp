// Author: JustKitkat
// Status: AC (post-contest)

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
    int s1,s2;
    cin>>n>>s1>>s2;
    vector<vi> adj1(n+1),adj2(n+1);
    int m1,m2;
    cin>>m1;
    set<ii>edges1;
    vi toFind(n+2);
    FOR(0,m1){
        int u,v;
        cin>>u>>v;
        adj1[u].pb(v);
        adj1[v].pb(u);
        edges1.insert({u,v});
        edges1.insert({v,u});
    }
    cin>>m2;
    FOR(0,m2){
        int u,v;
        cin>>u>>v;
        adj2[u].pb(v);
        adj2[v].pb(u);
        if(edges1.count({u,v}))toFind[u]=toFind[v]=1;
    }
    vector<vi>visited(n+2,vi(n+2)); // {u1,u2}
    priority_queue<pair<int,ii>,vector<pair<int,ii>>,greater<pair<int,ii>>>pq; // {dist,u1,u2}
    pq.push({0,{s1,s2}});
    int ans=-1;
    while(!pq.empty()){
        auto tmp=pq.top(); pq.pop();
        int dist=tmp.F,u1=tmp.S.F,u2=tmp.S.S;
        if(u1==u2 and toFind[u1]){
            ans=dist;
            break;
        }
        if(visited[u1][u2])continue;
        visited[u1][u2]=1;
        for(auto &x:adj1[u1]){
            for(auto &y:adj2[u2]){
                if(!visited[x][y])pq.push({dist+abs(x-y),{x,y}});
            }
        }
    }
    cout<<ans<<el;
    
}

/*

1
7 7 2
7
1 2
1 5
1 6
2 3
5 7
3 7
3 4
6
1 5
5 6
3 6
5 7
2 7
4 7

*/

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // freopen("out", "w", stdout);
    // freopen("in", "r", stdin);

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }

    //__time__ //Runtime
}
