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
#define FOR(a,b) for(auto i=a;i<b;++i)
#define DFOR(a,b) for(auto i=a;i>=b;--i)
#define JFOR(a,b) for(auto j=a;j<b;++j)
#define DJFOR(a,b) for(auto j=a;j>=b;--j)
#define show(x) cout << #x << " is " << x << el;
#define show2(x,y) cout << #x << " is " << x << " " << #y << " is " << y << el;
#define show3(x,y,z) cout << #x << " is " << x << " " << #y << " is " << y << " " << #z << " is " << z << el;
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

ll n=0, m=0, k=0, q=0;
char a[1005][1005];
int loop[1005][1005]={0};
int total=0;
set<ii>s,qvis;
int dfs(int y, int x){
    if(y<=0 or y>n or x<=0 or x>n)return 0;
    if(a[y][x]=='?')return loop[y][x];
    if(qvis.count({y,x}))return loop[y][x];
    if(loop[y][x] or s.count({y,x}))return 1;
    char v=a[y][x];
    s.insert({y,x});
    int ew=0;
    if(v=='U')ew=dfs(y-1,x);
    else if(v=='D')ew=dfs(y+1,x);
    else if(v=='R')ew=dfs(y,x+1);
    else ew=dfs(y,x-1);
    if(ew and !loop[y][x])loop[y][x]=1,total++;
    return ew;
}

int qdfs(int y, int x){
    if(y<=0 or y>n or x<=0 or x>n)return 0;
    if(qvis.count({y,x}))return 1;
    qvis.insert({y,x});
    if(loop[y][x] or qvis.count({y,x}))return loop[y][x];
    int ew=qdfs(y+1,x);
    if(ew)ew=qdfs(y-1,x);
    if(ew)ew=qdfs(y,x+1);
    if(ew)ew=qdfs(y,x-1);
    if(ew){loop[y][x]=1,total++;}//cout<<y<<' '<<x<<' '<<total<<el;}
    if(ew)return 1;
    char v=a[y][x];
    // qvis.insert({y,x});
    ew=0;
    if(v=='U')ew=qdfs(y-1,x);
    else if(v=='D')ew=qdfs(y+1,x);
    else if(v=='R')ew=qdfs(y,x+1);
    else if(v=='L')ew=qdfs(y,x-1);
    if(ew){loop[y][x]=1,total++;}
    return loop[y][x];
    // return loop[y][x];
}

void solve(int tc){
    cin>>n>>q;
    total=0;
    FOR(0,1005)JFOR(0,1005)a[i][j]='?',loop[i][j]=0;
    while(q--){
        int y,x;char t;
        cin>>y>>x>>t;
        a[y][x]=t;
        s.clear();
        qvis.clear();
        FOR(1,n+1){
            JFOR(1,n+1){
                if(i==y and j==x or a[i][j]=='?')
                    // show(dfs(i,j));
                    if(a[i][j]=='?')qdfs(i,j);//{if(qdfs(i,j))show3(i,j,loop[i][j]);}
                    else dfs(i,j);
            }
        }
        cout<<total<<el;
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
