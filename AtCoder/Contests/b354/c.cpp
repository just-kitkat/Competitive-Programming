// Author: JustKitkat
// Status: AC (there is a better solution with pure sort (dec order))

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
#define show(x) cerr << #x << " is " << x << endl;
#define show2(x,y) cerr << #x << " is " << x << " " << #y << " is " << y << endl;
#define show3(x,y,z) cerr << #x << " is " << x << " " << #y << " is " << y << " " << #z << " is " << z << endl;
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


void solve(int tc){
    int n;
    cin>>n;
    vector<vi> a(n,vi(3));
    FOR(0,n){cin>>a[i][0]>>a[i][1];a[i][2]=i;}
    set<vi>s;
    unordered_set<int> rm;
    sort(all(a));
    priority_queue<pair<int,int>>pq;
    for(auto x:a){
        while(!pq.empty() && pq.top().F>x[1]){
            pair<int,int> b=pq.top();
            rm.insert(b.S);
            pq.pop();
        }
        pq.push({x[1],x[2]});
    }
        
    //     s.insert(x);
    //     auto it=s.lower_bound(x);
    //     if(s.size()==1||s.begin()==it)continue;
    //     // show3(x[0],(*it)[0],(*it)[1]);
    //     it=prev(it);
    //     // cout<<'-'<<el;
    //     // show3(x[0],(*it)[0],(*it)[1]);
    //     vi b=*it;
    //     if(s.size()==1||s.begin()==it)continue;
    //     while(b[1]>x[1]){
    //         // show2((*it)[0],(*it)[1]);
    //         rm.insert((*it)[2]);
    //         s.erase(it);
    //         it=prev(it);
    //         b=*it;
    //         if(it==s.begin())break;
    //     }

    // }
    // sort(all(a));
    // int p1=0,p2=n-1;
    // while(p2>p1){
    //     if(a[p2][0]>a[p1][0]&&a[p2][1]<a[p1][1]){
    //         rm.insert(a[p1][2]);
    //         // show(a[p1][2]);
    //     }
    //     p1++;
    //     // show2(p1,p2);
    // }
    vi ans;
    FOR(0,n)if(!rm.count(i))ans.pb(i+1);
    cout<<ans.size()<<el;
    for(auto x:ans)cout<<x<<' ';
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //__output__ // Redirect output to test.out
    //__input__ // Read test.in for input

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }

    //__time__ //Runtime
}
// Note: int64_t for exactly 64 bit signed int