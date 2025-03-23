// #include "minerals.h"
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
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
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// #define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

const ll INF = 1e15;
const ll MOD = 1e9+7;
const double PI = acos(-1);
const auto BEG = std::chrono::high_resolution_clock::now(); //Begining of the program

constexpr int MAX_N = 43000;
constexpr ll MAX_CALLS = 1000000000000;

namespace {

void WrongAnswer(int code) {
  printf("Wrong Answer [%d]\n", code);
  exit(0);
}

int N;
int counterpart[2 * MAX_N + 1];

ll num_queries;
int num_kinds;
int on[2 * MAX_N + 1];
int countt[2 * MAX_N + 1];

int num_answers;
int answer[2 * MAX_N + 1];

}  // namespace

int Query(int x) {
    // show(x);
    if (!(1 <= x && x <= 2 * N)) {
        WrongAnswer(1);
    }
    if (++num_queries > MAX_CALLS) {
        WrongAnswer(2);
    }
    const int type = std::min(x, counterpart[x]);
    if (on[x]) {
        --on[x];
        --countt[type];
        if (countt[type] == 0) {
        --num_kinds;
        }
    } else {
        ++on[x];
        ++countt[type];
        if (countt[type] == 1) {
        ++num_kinds;
        }
    }
    return num_kinds;
}
int xx=0;
void Answer(int a, int b) {
    if(!xx){xx=1;show(num_queries);}  
    if (++num_answers > N) {
        WrongAnswer(6);
    }
    if (!(1 <= a && a <= 2 * N && 1 <= b && b <= 2 * N)) {
        WrongAnswer(3);
    }
    if (answer[a] != 0) {
        WrongAnswer(4);
    }
    answer[a] = b;
    if (answer[b] != 0) {
        WrongAnswer(4);
    }
    answer[b] = a;
    if (!(counterpart[a] == b && counterpart[b] == a)) {
        WrongAnswer(5);
    }
}

int prev=0;
vi options,group1,group2,in,out;
vii ans;
uset<int>vis;
int PARTITION(int x){
    return max(1,(int)((ld)x*0.3));
}
void determine(vi&grp1, vi&grp2, bool flipped){
    // query half in group 1
    vi new1, new2, new3, new4;
    int prev=-1;
    FOR(0,PARTITION((int)grp1.size())) prev=Query(grp1[i]), new1.pb(grp1[i]);
    FOR(PARTITION((int)grp1.size()),grp1.size()) new3.pb(grp1[i]);
    // show("n");
    int tmp=grp2.back();
    grp2.pop_back();
    for(auto &x:grp2){
        int q=(new2.size()==new1.size()?(flipped?prev:prev-5):Query(x));
        // show3(q,prev,x);
        if((prev==q and !flipped) or (prev!=q and flipped))new2.pb(x);
        else new4.pb(x);
        prev=q;
    }
    grp2.pb(tmp); //for debugging
    if(new2.size()!=new1.size())new2.pb(tmp);else new4.pb(tmp);
    // show("d");
    // show_vec(grp1);
    // show_vec(grp2);
    // show(flipped);
    // show_vec(new1);
    // show_vec(new2);
    // show_vec(new3);
    // show_vec(new4);
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
    // show_vec(options);

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

/*

1 2 3 4
5 6 7 8

20 
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40

4
1 2 3 4 5 6 7 8

4
1 5
2 6
3 4
7 8

*/

signed main() {
    // if (scanf("%d", &N) != 1) {
    //     fprintf(stderr, "Error while reading input\n");
    //     exit(1);
    // }
    // for (int i = 1; i <= N; ++i) {
    //     int x, y;
    //     if (scanf("%d%d", &x, &y) != 2) {
    //     fprintf(stderr, "Error while reading input\n");
    //     exit(1);
    //     }
    //     counterpart[x] = y;
    //     counterpart[y] = x;
    // }
    N = 43000;
    FOR(1,2*N+1)counterpart[i]=i+1,counterpart[i+1]=i,i++;
    Solve(N);
    if (num_answers != N) {
        WrongAnswer(6);
    }
    // assert(num_queries<4000000);
    printf("Accepted: %lld\n", num_queries);
    return 0;
}
