// Author: JustKitkat
// Status: WIP

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
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


struct node{
    int Start, End, Midpoint;
    int val;
    node *l, *r;

    node(int s, int e){
        Start = s;
        End = e;
        Midpoint = (Start + End)/2;

        if(Start == End){
            val = 0;
            return;
        }

        l = new node(Start, Midpoint);
        r = new node(Midpoint + 1, End);
		
        val = 0;
    }

    int query(int ql, int qr){
        if(ql <= Start && End <= qr){
            return val;
        }
        if(End < ql || qr < Start){
            return 0; //LLONG_MAX if taking min and vice versa, use 0 if sum
        }
        return l->query(ql, qr) + r->query(ql, qr);
    }

    void update(int qx, int qv){   

        if(Start == End){
            val = qv;
            return;
        }

        if(qx <= Midpoint) l->update(qx, qv);
        else r->update(qx, qv);

        val = l->val + r->val;

    }

};

void solve(int tc){
    int n;
    cin>>n;
    node *st = new node(0,n);
    FOR(0,n){
        int x;cin>>x;
        st->update(i,x);
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