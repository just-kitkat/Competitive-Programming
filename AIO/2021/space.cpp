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
#define __output__ { FILE* file = freopen("spaceout.txt", "w", stdout); }
#define __input__ { FILE* file = freopen("spacein.txt", "r", stdin); }

// PBDS -> initialise using `ordered_set s;` -> change to greater<int> for reversed order.
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
//#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAX_N = 1e5 + 5;
const ll INF = 1e9;
const double PI = acos(-1);
const auto BEG = std::chrono::high_resolution_clock::now(); //Begining of the program


struct node{
    int Start,End,Midpoint,Ind=-1;
    int val;
    int res=0;
    node *l, *r; 

    node(int s,int e, int ind){
        Ind = ind;
        Start=s;
        End=e;
        Midpoint=(Start+End)/2;
        val=0;
        if(Start==End){
            return;
        }
        l=new node(Start,Midpoint,-1);
        r=new node(Midpoint+1,End,-1);
    }

    pair<int,int> query(int a,int b, int k){
        // assert(End<a or b<Start);
        if(Start==End){//(a<=Start and End<=b){
            // show3("RETURN", val,Ind);
            return {val, Ind};
        }
        if(End<a or b<Start){
            return {1000000001,-1};
        }
        auto right = r->val;
        // show(right.F);
        // cout<<(right.F<=k)<<endl;
        if (right <= k) return r->query(a,b,k);
        else return l->query(a,b,k);
    }

    void update(int p,int v, int ind){   
        if(Start==End){
            val=v;
            Ind = ind;
            // cout<<Ind<<el;
            return;
        }
        // Ind = ind;
        if(p<=Midpoint) l->update(p,v,ind);
        else r->update(p,v,ind);
        val=min(l->val,r->val);
    }
} *root;


// ll n=0, m=0, k=0, q=0;
void solve(int tc){
    int n,f;
    cin>>n>>f;
    vi a(n);
    FOR(0,n)cin>>a[i];
    root = new node(0,n-1,-1);
    FOR(0,n)root->update(i,a[i],i);
    // cout<<"updated"<<endl;
    int ans=-1;
    FOR(0,n-1){
        int xx = root->query(i+1,n-1,f-a[i]).S - i;
        // show2(root->query(i+1,n-1,f-a[i]).S, i)
        // show(xx);
        // show(f-a[i]);
        ans=max(ans,xx);
    }

    cout<<(ans<=0?-1:ans+1);
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    __output__ // Redirect output to test.out
    __input__ // Read test.in for input

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }

    //__time__ //Runtime
}
