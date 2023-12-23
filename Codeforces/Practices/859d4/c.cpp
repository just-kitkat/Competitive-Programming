// Author: JustKitkat

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ar array
#define ll long long
#define ld long double

#define __time__ { auto duration = chrono::duration<double>( /* Show runtime */ \
chrono::high_resolution_clock::now() - beg); cout<<"Time: "<<duration.count()<<endl;}
#define __log__ { FILE* file = freopen("../../../Testcases/test.out", "w", stdout); }
#define __input__ { FILE* file = freopen("../../../Testcases/test.in", "r", stdin); }

const int MAX_N = 1e5 + 5;
const ll INF = 1e9;
const double PI = acos(-1);
const auto beg = std::chrono::high_resolution_clock::now(); //Begining of the program


void solve(int tc){
    int n;
    int nn;
    cin >> nn;
    string s;
    cin>>s;
    map<char,char> m;
    char cur='1';
    int f=1;
    while (nn--){
        if (m.count(s[nn])){
            if (m[s[nn]]!=cur){f=0;break;}
        }
        m[s[nn]]=cur;
        cur=='1'?cur='0':cur='1';
    }

    if (!f)cout<<"NO";
    else cout<<"YES";
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

   // __log__ // Redirect output to test.out
    //__input__ // Read test.in for input

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }

    //__time__ //Runtime
}