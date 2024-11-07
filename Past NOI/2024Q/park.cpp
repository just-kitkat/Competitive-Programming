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
const ll INF = LLONG_MAX;
const ll MOD = 1e9+7;
const double PI = acos(-1);
const auto BEG = std::chrono::high_resolution_clock::now(); //Begining of the program

ll n=0, m=0, k=0, q=0;

struct node{
    int Start, End, Midpoint;
    int val,w;
    node *l, *r;

    node(int s, int e){
        Start=s, End=e, Midpoint=(Start+End)/2;
        if(Start == End){
            val = INF;
            return;
        }

        l = new node(Start, Midpoint);
        r = new node(Midpoint+1, End);
        val = INF;
    }

    int query(int ql, int qr, int x, int w){
        if(Start==End)return Start;
        if((w==0 && l->val<=x) || (w==1 && l->val<INF))
            return l->query(ql,qr,x,w);
        return r->query(ql,qr,x,w);
    }

    void update(int qx, int qv){   
        if(Start == End){
            val = qv;
            return;
        }
        if(qx <= Midpoint) l->update(qx, qv);
        else r->update(qx, qv);
        val = min(l->val,r->val);
    }
};

void solve(int tc){
    cin>>q;
    node *stwilling=new node(0,q+5);
    node *st=new node(0,q+5);
    int a[q+5]={0};
    int join=0;
    FOR(0,q){
        int op;cin>>op;
        if(op==1){
            int s,w;cin>>s>>w;
            if(w)stwilling->update(join,s);
            else st->update(join,s);
            a[join]=s;
            join++;
        }else if(op==2){
            int x;cin>>x;x--;
            stwilling->update(x,INF);
            st->update(x,INF);
        }else{
            int b;cin>>b;
            vii ans;
            while(b>0){
                int ind1=st->query(0,q,b,0),ind2=stwilling->query(0,q,b,1);
                if(ind1>q and ind2>q)break;
                if(ind1<ind2){
                    b-=a[ind1];
                    ans.pb({ind1,a[ind1]});
                    st->update(ind1,INF);
                }else{
                    if(b<a[ind2]){
                        stwilling->update(ind2,a[ind2]-b);
                        a[ind2]-=b;
                        ans.pb({ind2,b});
                        b=0;
                    }else{
                        b-=a[ind2];
                        ans.pb({ind2,a[ind2]});
                        stwilling->update(ind2,INF);
                    }
                }
            }
            cout<<ans.size()<<el;
            for(auto &x:ans)cout<<x.F+1<<' '<<x.S<<el;
        }
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
