#include "minerals.h"
// Author: JustKitkat
// Status: WIP

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;

// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
mt19937_64 rnd(37);//chrono::steady_clock::now().time_since_epoch().count());

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

int prev=0;
vi options,group1,group2,in,out;
vii ans;
uset<int>vis;
int PARTITION(int x){
    return max(1,(int)((ld)x*0.3));
}
void determine(vi&grp1, vi&grp2, bool flipped){
    vi new1, new2, new3, new4;
    int prev=-1;
    FOR(0,PARTITION((int)grp1.size())) prev=Query(grp1[i]), new1.pb(grp1[i]);
    FOR(PARTITION((int)grp1.size()),grp1.size()) new3.pb(grp1[i]);
    int tmp=grp2.back();
    grp2.pop_back();
    for(auto &x:grp2){
        int q=(new2.size()==new1.size()?(flipped?prev:prev-1):Query(x));
        if((prev==q and !flipped) or (prev!=q and flipped))new2.pb(x);
        else new4.pb(x);
        prev=q;
    }
    if(new2.size()!=new1.size())new2.pb(tmp);else new4.pb(tmp);
    if(new1.size()==1)ans.pb({new1[0],new2[0]});
    else determine(new1,new2,!flipped);
    if(new3.size()==1)ans.pb({new3[0],new4[0]});
    else determine(new3,new4,flipped);
}

void Solve(int N) { 
    // Query(x) and Answer(a,b) 
    FOR(1,2*N+1)options.pb(i);
    srand(37);
    random_shuffle(all(options));

    // split them into 2 groups
    int prev=0;
    for(auto &x:options){
        int q=Query(x);
        if(q==prev) group1.pb(x);
        else group2.pb(x);
        prev=q;
    }

    determine(group1,group2,1);

    // for(auto &x:ans)show2(x.F,x.S);
    for(auto &x:ans)Answer(x.F,x.S);

}  
