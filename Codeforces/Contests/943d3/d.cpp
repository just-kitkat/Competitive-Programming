// Author: JustKitkat
// Status: AC

#include <bits/stdc++.h>

using namespace std;
#define int long long
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
// #define pb push_back
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

#define __time__ { auto duration = chrono::duration<double>( /* Show runtime */ \
chrono::high_resolution_clock::now() - BEG); cout<<"Time: "<<duration.count()<<endl;}
#define __output__ { FILE* file = freopen("../../../Testcases/test.out", "w", stdout); }
#define __input__ { FILE* file = freopen("../../../Testcases/test.in", "r", stdin); }

const int MAX_N = 1e5 + 5;
const ll INF = 1e9;
const double PI = acos(-1);
const auto BEG = std::chrono::high_resolution_clock::now(); //Begining of the program

int n,k,pb,ps;
vi p,a;

void solve(int tc){
    cin>>n>>k>>pb>>ps;
    pb--;ps--;
    int originalpb=pb,originalps=ps,originalk=k;
    p.resize(n);
    a.resize(n);
    FOR(0,n)cin>>p[i];
    FOR(0,n)cin>>a[i];
    int oneRound=0; for(auto x:a)oneRound+=x;

    int scoreB=0,scoreS=0,maxB=0,maxS=0;
    vi maxprefB,maxprefS;
    FOR(0,min(n,originalk)){
        scoreB+=a[pb];
        maxB=max(scoreB+a[pb]*(k-1),maxB);
        // show2(scoreB,maxB);
        // maxprefB.push_back(max(
        //     (maxprefB.empty()?0:maxprefB.back())+a[pb],
        //     maxB));
        pb=p[pb]-1;

        scoreS+=a[ps];
        maxS=max(scoreS+a[ps]*(k-1),maxS);
        // show2(scoreS,maxS);
        // maxprefS.push_back(max(
        //     (maxprefS.empty()?0:maxprefS.back())+a[ps],
        //     maxS));
        ps=p[ps]-1;

        k--;
    }

    // maxB=scoreB*(k/n) + maxprefB[k%n];
    // maxS=scoreS*(k/n) + maxprefS[k%n];
    // if(k<n){
    //     maxB=scoreB;
    // }
    // show2(maxB,maxS);
    // show2(scoreB,scoreS);
    // show_vec(maxprefB);
    if(maxB==maxS)cout<<"Draw\n";
    else if(maxB<maxS)cout<<"Sasha\n";
    else cout<<"Bodya\n";

}
/*
1
4 2 3 2
4 1 2 3
7 2 5 6

*/

signed main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);

    //__output__ // Redirect output to test.out
    //__input__ // Read test.in for input

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }

    //__time__ //Runtime
}
// Note: int64_t for exactly 64 bit signed int