// Author: JustKitkat
// Status: WIP

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

#define LS(S) ((S)&-(S))

class FT{
private:
    vi ft;
public:
    FT(int m){ft.assign(m+1,0);}
    void build(const vi &f){
        int m=(int)f.size()-1;
        ft.assign(m+1,0);
        for(int i=1;i<=m;++i){
            ft[i]+=f[i];
            if(i+LS(i)<=m)ft[i+LS(i)]+=ft[i];
        }
    }
    FT(const vi &f){build(f);}
    FT(int m, const vi &s){
        vi f(m+1,0);
        for(int i=0;i<(int)s.size();++i){
            ++f[s[i]];
        }
        build(f);
    }
    int rsq(int j){
        int sum=0;
        for(;j;j-=LS(j))sum+=ft[j];
        return sum;
    }
    int rsq(int i, int j){return rsq(j)-rsq(i-1);}

    void update(int i, int v){
        for(;i<(int)ft.size();i+=LS(i))ft[i]+=v;
    }
    int select(int k){
        int lo=1,hi=ft.size()-1;
        FOR(0,30){
            int mid=(lo+hi)/2;
            (rsq(1,mid)<k)?lo=mid:hi=mid;

        }return hi;
    }
};

class RUPQ{
private:
    FT ft;
public:
    RUPQ(vi m):ft(FT(m)){}
    void range_update(int ui,int uj, int v){
        ft.update(ui,v);
        ft.update(uj+1, -v);
    }
    int point_query(int i){return ft.rsq(i);}
};

class RURQ{
private:
    RUPQ rupq;
    FT purq;
public:
    RURQ(vi m) : rupq(RUPQ(m)),purq(FT(m)){}
    void range_update(int ui, int uj, int v){
        rupq.range_update(ui,uj,v);
        purq.update(ui,v*(ui-1));
        purq.update(uj+1,-v*uj);
    }
    int rsq(int j){
        return rupq.point_query(j)*j-purq.rsq(j);
    }
    int rsq(int i, int j){return rsq(j)-rsq(i-1);}
};

void solve(int tc){
    int n;cin>>n;
    vi aa(n);
    FOR(0,n)cin>>aa[i];
    RURQ st(aa);
    int q;
    cin>>q;

    FOR(0,q){
        int a,b,c,d;
        cin>>a>>b>>c;
        if(a==1){cin>>d;st.range_update(b,c,d);}
        else cout<<st.rsq(b,c)<<el;
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