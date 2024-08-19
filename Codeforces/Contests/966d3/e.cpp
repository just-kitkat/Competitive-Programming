// Author: JustKitkat
// Status: AC

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

#define __time__ { auto duration = chrono::duration<double>( /* Show runtime */ \
chrono::high_resolution_clock::now() - BEG); cout<<"Time: "<<duration.count()<<endl;}
#define __output__ { FILE* file = freopen("../../../Testcases/test.out", "w", stdout); }
#define __input__ { FILE* file = freopen("../../../Testcases/test.in", "r", stdin); }

// PBDS -> initialise using `ordered_set s;` -> change to greater<int> for reversed order.
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
//#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAX_N = 1e5 + 5;
const ll INF = 1e9;
const double PI = acos(-1);
const auto BEG = std::chrono::high_resolution_clock::now(); //Begining of the program

ll n=0, m=0, k=0, q=0;
void solve(int tc){
    cin>>n>>m>>k;
    int w;
    cin>>w;
    vi a(w);
    FOR(0,w)cin>>a[i];
    ii mid={n/2,m/2};
    sort(all(a),greater<int>());
    vector<vi> grid(n,vi(m));
    vi st;
    FOR(0ll,n){
        JFOR(0ll,m){
            // corner
            if((i==0 or i==n-1) && (j==0 or j==m-1))st.pb(1);
            // else if(i==0 || i==n-1 || j==0 || j==m-1)st.pb(k*)
            else{
                int numx=0,numy=0;
                // no overlap
                if(i+1>=k && (n-i)>=k)numx = k;
                // overlap
                else numx = min({n-k+1,i+1,n-i});

                // no overlap
                if(j+1>=k && (m-j)>=k)numy = k;
                // overlap
                else numy = min({m-k+1,j+1,m-j});

                st.pb(numx*numy);
            }
        }
    }
    // show_vec(st);
    sort(all(st));
    int ans=0;
    if(!st.empty())
        for(auto &x:a){
            ans+=x*st.back();
            st.pop_back();
            if(st.empty())break;
        }
    
    cout<<ans<<el;
    // int p=0;
    // int free=0;
    // k++;
    // int ans=0;
    // while(p<n){
    //     if(free==0)k--,free=(n-k-k+2)*(m-k-k+2)-p;
    //     if(n-k-k+2<0 || m-k-k+2<0)free=0;
    //     if(free==0)continue;
    //     ans+=a[p]*(k*k);
    //     p++;
    //     free--;
    //     show3(k,ans,free);
    // }
    // cout<<ans<<el;
    
}
/*
center (edge - k) -> place all highest numbers

1
9 5 5
6
6 7 14 16 16 6

2
3 4 2
9
1 1 1 1 1 1 1 1 1
2 1 1
2
5 7
*/

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //__output__ // Redirect output to test.out
    //__input__ // Read test.in for input

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }

    //__time__ //Runtime
}
