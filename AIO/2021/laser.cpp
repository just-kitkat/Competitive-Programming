// Author: JustKitkat
// Status: 44/100

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
#define show(x) ;//cerr << #x << " is " << x << endl;
#define show2(x,y) ;//cerr << #x << " is " << x << " " << #y << " is " << y << endl;
#define show3(x,y,z) ;//cerr << #x << " is " << x << " " << #y << " is " << y << " " << #z << " is " << z << endl;
#define show_vec(a) ;//for(auto &x:a)cerr<<x<<(!x?" ":"")<<' ';cerr<<endl;
#define discretize(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

#define __time__ { auto duration = chrono::duration<double>( /* Show runtime */ \
chrono::high_resolution_clock::now() - BEG); cout<<"Time: "<<duration.count()<<endl;}
#define __output__ { FILE* file = freopen("laserout.txt", "w", stdout); }
#define __input__ { FILE* file = freopen("laserin.txt", "r", stdin); }

// PBDS -> initialise using `ordered_set s;` -> change to greater<int> for reversed order.
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
//#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAX_N = 1e5 + 5;
const ll INF = 1e9;
const double PI = acos(-1);
const auto BEG = std::chrono::high_resolution_clock::now(); //Begining of the program

ll n=0, m=0, k=0;
void solve(int tc){
    cin>>n;
    string a,b;
    cin>>a>>b;
    if(b==string(n,'D')+string(n,'R')) swap(a,b);
    if(a==string(n,'D')+string(n,'R')){
        int r=0,d=0;
        int ans=0;
        for(auto &x:b){
            if(x=='R')r++;
            else d++;
            ans=max(ans,min(r,n-d));
        }
        cout<<ans;
        return;
    }
    else{
        if(b[0]=='R')swap(a,b);
        int grid[n+5][n+5];
        FOR(0,n+5)JFOR(0,n+5)grid[i][j]=0;
        int x=0,y=0;
        for(auto &z:a){
            if(z=='D')grid[y][x]=-1;
            x+=z=='R';
            y+=z=='D';
        }
        grid[y][x]=-1;
        x=0,y=0;
        for(auto &z:b){
            if(z=='R')grid[y][x]=-1;
            x+=z=='R';
            y+=z=='D';
        }
        grid[y][x]=-1;
        for(auto &x:grid){show_vec(x);}
        int ans=1;
        int xx=0,yy=0;
        // show("preprocess done");
        queue<vi> mainq;
        mainq.push({0,0,3});
        unordered_set<string>ss;
        while(!mainq.empty()){
            auto zz=mainq.front();
            xx=zz[0],yy=zz[1];
            mainq.pop();
            string whee=to_string(xx)+","+to_string(yy);
            if(ss.count(whee))continue;
            ss.insert(whee);
            if(grid[yy][xx]==-1)continue;
            mainq.push({xx+1,yy,1});
            mainq.push({xx,yy+1,2});
            mainq.push({xx+1,yy+1,3});
            show("==============");
            show2(xx,yy);
            queue<vi>q;
            q.push({xx,yy,3,1});
            while(!q.empty()){
                auto z=q.front();
                q.pop();
                show_vec(z);
                // if(!q.empty())ans=max(ans,q.front()[3]-1);
                // show(ans);
                int x=z[0],y=z[1];
                int d=z[3];
                if(grid[y][x+1]!=-1 && grid[y+1][x]!=-1 && grid[y+1][x+1]!=-1){
                    if(z[2]==1) q.push({x+1,y,1,d+1});
                    if(z[2]==2) q.push({x,y+1,2,d+1});
                    if(z[2]==3) {
                        q.push({x+1,y,1,d+1});
                        q.push({x,y+1,2,d+1});
                        q.push({x+1,y+1,3,d+1});
                        ans=max(ans,d+1);
                        show2(ans,d+1);
                    }
                    
                    // show2(d,ans);
                }else break;
                show(ans);
            }
        }
        show(ans);
        cout<<ans;
    }
}
/*
                    if(grid[y][x+1]!=-1 && z[2]==1) q.push({x+1,y,1,d+1});
                    if(grid[y+1][x]!=-1 && z[2]==2) q.push({x,y+1,2,d+1});
                    if(grid[y+1][x+1]!=-1 && z[2]==3) 
                        q.push({x+1,y,1,d+1}),
                        q.push({x,y+1,2,d+1}),
                        q.push({x+1,y+1,3,d+1});
                    else if(z[2]==3)break;
*/
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
