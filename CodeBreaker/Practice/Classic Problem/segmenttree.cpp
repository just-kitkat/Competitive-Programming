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

class ST{
private:
    int n;
    vi A,st,lazy;
    int l(int p){return p<<1;}
    int r(int p){return (p<<1)+1;}
    int conquer(int a,int b){if(a==-1)return b;if(b==-1)return a;return min(a,b);}
    void build(int p,int L, int R){
        if(L==R)st[p]=A[L];
        else{
            int m=(L+R)/2;
            build(l(p),L,m);
            build(l(p),m+1,R);
            st[p]=conquer(st[l(p)],st[r(p)]);
        }
    }
    void propagate(int p, int L, int R){
        if(lazy[p]!=-1){
            st[p]=lazy[p];
            if(L!=R)lazy[l(p)]=lazy[r(p)]=lazy[p];
            else A[L]=lazy[p];
            lazy[p]=-1;
        }
    }
    int RMQ(int p, int L, int R, int i, int j){
        propagate(p,L,R);
        if(i>j)return -1;
        if((L>=i)&&(R<=j))return st[p];
        int m=(L+R)/2;
        return conquer(RMQ(l(p),L,m,i,min(m,j)),RMQ(r(p),m+1,R,max(i,m+1),j));
    }

    void update(int p,int L,int R, int i, int j, int val){
        propagate(p,L,R);
        if(i>j)return;
        if((L>=i)&&(R<=j)){lazy[p]=val;propagate(p,L,R);}
        else{
            int m=(L+R)/2;
            update(l(p),L,m,i,min(m,j),val);
            update(r(p),m+1,R,max(i,m+1),j,val);
            int lll=(lazy[l(p)]!=-1)?lazy[l(p)]:st[l(p)];
            int rrr=(lazy[r(p)]!=-1)?lazy[r(p)]:st[r(p)];
            st[p]=(lll<=rrr)?st[l(p)]:st[r(p)];
            
        }
    }
public:
    ST(int sz):n(sz),st(4*n),lazy(4*n, -1){}
    ST(const vi &initialA):ST((int)initialA.size()){
        A=initialA;
        build(1,0,n-1);
    }
    void update(int i, int j, int val){update(1,0,n-1,i,j,val);}
    int RMQ(int i,int j){return RMQ(1,0,n-1,i,j);}
};

void solve(int tc){
    int n,q;
    cin>>n>>q;
    vi a(n,0);
    ST st(a);

    FOR(0,q){
        int a,b,c;
        cin>>a>>b>>c;
        //1 update, 2 min query
        if(a==1)st.update(b,b,c);
        else cout<<st.RMQ(b,c)<<el;
    }
    
}

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