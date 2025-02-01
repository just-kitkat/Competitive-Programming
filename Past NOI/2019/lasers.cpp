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
    int l,r;
    cin>>l>>r;
    set<int>intervals;
    umap<int,int>end;
    intervals.insert(1);
    intervals.insert(l+1);
    end[1]=l;
    end[l+1]=1e15;
    FOR(0,r){
        int x;cin>>x;
        vi a(x);
        for(auto &x:a)cin>>x;
        int last=l,start=0;
        for(auto &x:a)start+=x;
        reverse(all(a));
        for(auto &x:a){
            if(last-x<start){ // HAH OVERLAP
                // remove [last-x+1, start]
                auto previt=intervals.upper_bound(start);
                if(previt!=intervals.begin()){
                    int prev=*--previt;
                    // show2(start,last-x);
                    // show(prev);
                    if(end[prev]>start){
                        end[start+1]=end[prev];
                        intervals.insert(start+1);
                    }
                    if(prev>last-x and intervals.count(prev)) intervals.erase(prev),end[prev]=-1;
                    auto prevvit=intervals.upper_bound(last-x);
                    if(prevvit!=intervals.begin()){ 
                        int prevv=*--prevvit;
                        end[prevv]=min(end[prevv],last-x);
                    }
                    
                    auto rem=intervals.upper_bound(start);
                    if(rem!=intervals.begin()){
                        --rem;
                        while(true){
                            if(*rem>=last-x+1)intervals.erase(rem);
                            else break;
                            rem=intervals.upper_bound(start);
                            if(rem!=intervals.begin())--rem;
                            else break;
                        }
                    }
                    // show("intervals");
                    // for(auto &x:intervals)cout<<x<<','<<end[x]<<"  ";cout<<endl;
                }
            }
            start-=x;
            last-=x;
        }
    }
    int ans=0;
    int last=0;
    for(auto &x:intervals){
        if(x>last+1)ans+=x-last-1;
        last=end[x];
    }
    cout<<ans;
    
}
/*
1 2 3 4 5 6 7 8 9 10
- - - - - - -     - 
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
