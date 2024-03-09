// Author: JustKitkat
// Status: AC

#include <bits/stdc++.h>

using namespace std;

#define el "\n"
#define arr array
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vii vector<pair<int,int>>
#define vllll vector<pair<ll,ll>>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(a) (a).begin(), (a).end()
#define FOR(a,b) for(auto i=a;i<b;++i)
#define DFOR(a,b) for(auto i=a;i>=b;--i)
#define JFOR(a,b) for(auto j=a;j<b;++j)
#define DJFOR(a,b) for(auto j=a;j>=b;--j)

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

#define __time__ { auto duration = chrono::duration<double>( /* Show runtime */ \
chrono::high_resolution_clock::now() - BEG); cout<<"Time: "<<duration.count()<<endl;}
#define __output__ { FILE* file = freopen("../../../Testcases/test.out", "w", stdout); }
#define __input__ { FILE* file = freopen("../../../Testcases/test.in", "r", stdin); }

const int MAX_N = 1e5 + 5;
const ll INF = 1e9;
const double PI = acos(-1);
const auto BEG = std::chrono::high_resolution_clock::now(); //Begining of the program

class UnionFind{
private:
    vi p,rank,setSize;
    int numSets;
public:
    UnionFind(int N){
        p.assign(N, 0);FOR(0,N)p[i]=i;
        FOR(0,N)rank.pb(i);
        setSize.assign(N,1);
        numSets=N;
    }

    int findSet(int i){return(p[i]==i)?i:(p[i]=findSet(p[i]));}
    bool isSameSet(int i,int j){return findSet(i)==findSet(j);}
    int numDisjointSets(){return numSets;}
    int sizeOfSet(int i){return setSize[findSet(i)];}
    int getRank(int i){return rank[findSet(i)];}
    
    void unionSet(int i, int j){
        if(isSameSet(i,j))return;
        int x = findSet(i),y=findSet(j);
        if(rank[x]>rank[y])swap(x,y);
        p[x]=y;
        // if(rank[x]==rank[y])++rank[y];
        setSize[y]+=setSize[x];
        --numSets;
    }
};

void solve(int tc){
    int n,c;
    cin>>n>>c;
    UnionFind UF(n+5);
    vi f(n+5,0);
    vi ans;
    FOR(0,c){
        int a;cin>>a;
        // cout<<"Iteration i: "<<i<<el;
        if(f[a]==0){
            f[a]=1;
            if(f[a+1])UF.unionSet(a,a+1);
            if(f[a-1])UF.unionSet(a,a-1);
            ans.pb(a);
        }else{
            int x=UF.sizeOfSet(a);
            int r=UF.getRank(a);
            // cout<<r<<' '<<x<<' '<<a<<el;
            if(r==x){
                if(f[n]){
                    x=UF.sizeOfSet(n);
                    f[n-x]=1;
                    ans.pb(n-x);
                    a=n-x;
                }else{
                    f[n]=1;
                    ans.pb(n);
                    a=n;
                }
            }else{
                int m=r-x;
                f[m]=1;
                ans.pb(m);
                a=m;
            }
            if(f[a+1])UF.unionSet(a,a+1);
            if(f[a-1])UF.unionSet(a,a-1);
        }
    }
    for(auto x:ans)cout<<x<<el;
    
}
/*
5 5
3
2
2
2
1
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //__output__ // Redirect output to test.out
    //__input__ // Read test.in for input

    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }

    //__time__ //Runtime
}
// Note: int64_t for exactly 64 bit signed int