// Author: JustKitkat
// Status: AC

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
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
// using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// #define ordered_multiset tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAX_N = 1e5 + 5;
const ll INF = 1e9;
const double PI = acos(-1);
const auto BEG = std::chrono::high_resolution_clock::now(); //Begining of the program

ll n=0, m=0, k=0, q=0;
void solve(int tc){
    cin>>n>>m;
    vi a(n),b(n);
    FOR(0,n)cin>>a[i]>>b[i];
    vi every, aa=a;
    sort(all(aa));
    multiset<int>s;
    for(auto &x:a)every.pb(x);
    sort(all(every),greater<int>());
    FOR(0,m)s.insert(every[i]);
    // int hi=every[m-1];
    for(auto &x:b)every.pb(x);
    discretize(every);
    // hi=lower_bound(all(every),hi)-every.begin();
    int hi=(int)every.size()-1, lo=0, mid=(hi+lo)/2,window=m;
    int Acount,count,x,maxcount,tmpmaxcount;
    while(lo<=hi){
        mid=(hi+lo)/2;
        // show3(lo,mid,hi);
        // show(every[mid]);
        Acount=n-(lower_bound(all(aa),every[mid])-aa.begin()),
        count=0,
        x=every[mid],maxcount=0;
        // show(Acount);
        maxcount=Acount;
        tmpmaxcount=0;
        FOR(0,n){
            if(a[i]>=x && b[i]<x)count--;
            else if(a[i]>=x && b[i]>=x);
            else if(a[i]<x && b[i]<x);
            else count++;
            count=max(count,0ll);
            tmpmaxcount=max(tmpmaxcount,count);
        }
        // show2(tmpmaxcount,Acount);
        if(tmpmaxcount+Acount>=m)lo=mid+1;
        else hi=mid-1;
        maxcount=max(maxcount,count+Acount);
        // show3(lo,mid,hi);
        // show(every[mid]);
        // cout<<"====================\n";
    }
    if(tmpmaxcount+Acount<m)mid--;
    // show(every[mid]);
    // if(maxcount+1<m)mid--;
    cout<<every[mid];
}
/*
m=5
6 5
1 11
1 11
11 1
1 11
1 11
20 1
*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //__output__ // Redirect output to test.out
    //__input__ // Read test.in for input

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }

    //__time__ //Runtime
}
