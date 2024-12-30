// Author: JustKitkat
// Status: WIP

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
    cin>>n>>k;
    vii a(n);
    vi aa;
    FOR(0,n)cin>>a[i].F;
    FOR(0,n)cin>>a[i].S;
    sort(all(a));
    int highest = a.back().F;
    int highestmodi = -1;
    int med = a[(n-1)/2].F;
    for(auto &x:a){aa.pb(x.F);if(x.S)highestmodi=max(highestmodi,x.F);}
    sort(all(aa));

    if(highestmodi==-1){
        cout<<highest+a[(n-2)/2].F<<el;\
    }else if(highestmodi+k > highest){
        a.erase(find_if(
            all(a),[highestmodi](const auto &p){return p.first==highestmodi;}
        ));
        cout<<highestmodi+k+a[(n-2)/2].F<<el;
    }else{
        int lo=0,hi=3e9;
        while(lo<hi){
            int mid=(hi+lo+1)/2;
            int cnt=0;
            int kk=k;
            DFOR(n-2,0){
                if(a[i].S==1 && a[i].F>=mid)cnt++;
                else if(a[i].S==1 && a[i].F<mid && kk>=mid-a[i].F)
                    cnt++,kk-=mid-a[i].F;
                else if(a[i].S==0 && a[i].F>=mid)
                    cnt++;
            }
            // show3(lo,mid,hi); show(cnt);
            if(n-cnt-1 < (n-2)/2 + 1)lo=mid;
            else hi=mid-1;
        }
        // // show3(lo,mid,hi);
        // mid=lo;
        // int cnt=0;
        // int kk=k;
        // DFOR(n-2,0){
        //     if(a[i].S==1 && a[i].F>=mid)cnt++;
        //     else if(a[i].S==1 && a[i].F<mid && kk>=mid-a[i].F)
        //         cnt++,kk-=mid-a[i].F;
        //     else if(a[i].S==0 && a[i].F>=mid)
        //         cnt++;
        // }
        // // show3(lo,mid,hi); show(cnt);
        // if(n-cnt-1 <= (n-2)/2 + 1)lo--;
        // // show(lo);
        cout<<highest+lo<<el;
    }
    
}
/*
4 5
1 2 3 10
1 0 1 0

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
