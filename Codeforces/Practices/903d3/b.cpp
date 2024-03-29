// Author: JustKitkat
// Status: WIP

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ar array
#define ll long long
#define ld long double

#define __time__ { auto duration = chrono::duration<double>( /* Show runtime */ \
chrono::high_resolution_clock::now() - BEG); cout<<"Time: "<<duration.count()<<endl;}
#define __log__ { FILE* file = freopen("../../../Testcases/test.out", "w", stdout); }
#define __input__ { FILE* file = freopen("../../../Testcases/test.in", "r", stdin); }

const int MAX_N = 1e5 + 5;
const ll INF = 1e9;
const double PI = acos(-1);
const auto BEG = std::chrono::high_resolution_clock::now(); //Begining of the program


void solve(int tc){
    vector<int> n;
    for (int i=0;i<3;i++){int x;cin>>x;n.push_back(x);}

    int mn=min(min(n[0],n[1]),n[2]);
    int x=3;
    while (x--){
        int sz=n.size();
        for (int i=0;i<sz;i++){
            if (n[i]>mn){
                n.push_back(n[i]-mn);
                n[i]=mn;
                break;
            }
        }
    }
    int f=0;
    for (auto x:n)if(x!=mn)f=1;
    if (f)cout<<"NO";
    else cout <<"YES";
    cout<<endl;
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //__log__ // Redirect output to test.out
    //__input__ // Read test.in for input

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }

    //__time__ //Runtime
}