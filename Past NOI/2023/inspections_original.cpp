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
#define FOR(a,b) for(auto i=a;i<b;++i)
#define DFOR(a,b) for(auto i=a;i>=b;--i)
#define JFOR(a,b) for(auto j=a;j<b;++j)
#define DJFOR(a,b) for(auto j=a;j>=b;--j)
#define show(x) cerr << #x << " is " << x << endl;
#define show2(x,y) cerr << #x << " is " << x << " " << #y << " is " << y << endl;
#define show3(x,y,z) cerr << #x << " is " << x << " " << #y << " is " << y << " " << #z << " is " << z << endl;
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
const ll INF = 1e15;
const ll MOD = 1e9+7;
const double PI = acos(-1);
const auto BEG = std::chrono::high_resolution_clock::now(); //Begining of the program

vi solve2(int tc){
    ll n=0, m=0, k=0, q=0;
    cin>>n>>m>>q;
    //machine, task, safety
    vi l(m),r(m);vll s(q);
    FOR(0,m)cin>>l[i]>>r[i];
    FOR(0,q)cin>>s[i];
    map<int, int> lastAccessed;
    vll occ;
    ll ind=0;
    FOR(0,m){
        JFOR(l[i],r[i]+1){
            occ.pb(lastAccessed.count(j)==0?-1:ind-lastAccessed[j]-1);
            lastAccessed[j]=ind;
            ind++;
        }
    }

    // for(auto x:occ)cout<<x<<' ';cout<<el;
    vll ans;
    FOR(0,q){
        ans.pb(0);
        for(auto x:occ)ans.back()+=(x>=s[i]);
    }
    for(auto x:ans)cout<<x<<' ';cout<<el;
    return ans;
}
vi solve(int tc){
    ll n=0, m=0, k=0, q=0;
    cin>>n>>m>>q;
    
    vii a(m);
    for(auto &x:a)cin>>x.F>>x.S;

    umap<int,int> val;
    set<int> interval;
    interval.insert(1);
    val[1]=INF;
    interval.insert(INF);
    val[INF]=INF; // redundant
    int cnt=0;

    umap<int,int> ans;
    for(auto &x:a){
        vi to_remove;
        FOR(x.F,x.S+1){
            // show(i);
            // find the interval that contains i
            auto it=interval.upper_bound(i);
            int upper=*it-1;
            int lower=*--it;
            to_remove.pb(lower);
            int last_accessed=min(val[lower],cnt+i-x.F)+(i-lower);
            // interval [lower, upper] = last_accessed
            if(val[lower]<INF)
                ans[cnt+(i-x.F)-last_accessed]+=min(upper,x.S)-i+1;
            // show2(x.F,x.S);
            // show(last_accessed);
            // show2(cnt,cnt+i-x.F-last_accessed);
            // show2(i,min(upper,x.S));
            // show2(lower,upper);
            // show_vec(interval);
            i=upper; // will add 1 once the loop ends
            // show2(i,x.S+1);
        }
        // update intervals
        // show(val[*--interval.upper_bound(x.S+1)]);
        if(!interval.count(x.S+1))
            val[x.S+1]=val[*--interval.upper_bound(x.S+1)]+x.S-to_remove.back()+1;
        else ;
        FOR(1,to_remove.size()){
            interval.erase(to_remove[i]);
        }
        // show(*interval.upper_bound(x.S));
        // show(val[*interval.upper_bound(x.S)]);
        // if(to_remove.back()==*--interval.upper_bound(x.S))val[x.S+1]=val[*interval.upper_bound(x.S)];
        // val[x.S+1]=val[to_remove.back()]+x.S-to_remove.back()+1;
        interval.insert(x.S+1);
        interval.insert(x.F);
        val[x.F]=cnt;
        cnt+=x.S-x.F+1;
        // show("to_remove");
        // show_vec(to_remove);
        // show("=========== ans")
        // for(auto &x:ans){
        //     cout<<x.F<<": "<<x.S<<endl;
        // }
        // show("=========== interval");
        // for(auto &x:interval){
        //     cout<<x<<": "<<val[x]<<endl;
        // }
    }
    // for(auto &x:ans)cout<<x.F<<": "<<x.S<<endl;
    vi queries(q);
    for(auto &x:queries)cin>>x;
    map<int,int>res;
    for(auto &x:queries)res[-x]=0;
    int sm=0,p=0;
    vii process;
    for(auto &x:ans)process.pb({x.F,x.S});
    sort(all(process),greater<ii>());
    // show("process")
    // for(auto &x:process)cout<<x.F-1<<' '<<x.S<<" , ";
    // cout<<el;
    // show("ans");
    // for(auto &x:ans)cout<<x.F<<": "<<x.S<<endl;
    // show("res");
    // for(auto &x:res)cout<<x.F<<": "<<x.S<<endl;
    for(auto &x:res){
        while(p!=process.size() and process[p].F>-x.F)sm+=process[p].S,p++;
        x.S=sm;assert(sm<(int)1e12);
		
    }
    vi anss;
    for(auto &x:queries){cout<<res[-x]<<' ';anss.pb(res[-x]);}
    return anss;

}

/*
5 3 14
1 5
1 2
4 5
0 1 2 3 4 5 6 7 8 9 10 11 12 13

5 4 8
1 5
1 4
1 3
1 2
7 6 5 4 3 2 1 0

1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
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
        auto _=solve(t);
        // freopen("CON","w",stdout);
        // freopen("in2", "r", stdin);
        // auto s1=solve(t);
        // cout<<endl;
        // freopen("in2", "r", stdin);
        // auto s2=solve2(t);
        // assert(s1==s2);
        // show("done");
        // FOR(1,10+1){
        //     JFOR(1,10+1){
        //         for(int k=1;k<=10;++k){
        //             for(int l=1;l<=10;++l){
        //                 freopen("in","w",stdout);
        //                 cout<<"10 4 20"<<el;
        //                 cout<<"1 "<<i<<el;
        //                 cout<<"1 "<<j<<el;
        //                 cout<<"1 "<<k<<el;
        //                 cout<<"1 "<<l<<el;
        //                 cout<<"0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 1000000000000"<<endl;
        //                 fclose(stdout);
        //                 // freopen("CON","w",stdout);
        //                 freopen("in", "r", stdin);
        //                 auto s1=solve(t);
        //                 cout<<endl;
        //                 freopen("in", "r", stdin);
        //                 auto s2=solve2(t);
        //                 assert(s1==s2);
        //                 cout<<"-----------"<<endl;
        //             }
        //         }
        //     }
        // }
        // show("done");
    }

    //__time__ //Runtime
}
