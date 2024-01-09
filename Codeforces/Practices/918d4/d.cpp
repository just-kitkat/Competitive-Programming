// Author: JustKitkat
// Status: AC

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
    int n;
    string s="";
    cin>>n;
    cin>>s;
    string res="";
    bool nxt=false,dot=false;
    unordered_map<char,char> m={{'a','v'},{'b','c'},{'c','c'},{'d','c'},{'e','v'}};
    for (int i=0;i<n;i++){
        if( m[s[i]]=='v' && i<n-2 && m[s[i+2]]=='c' )nxt=true;
        else if (m[s[i]]=='v'&&i<n-2)dot=true;
        res+=s[i];
        if (dot)res+='.';
        dot=false;
        if (m[s[i]]=='c'&&nxt){res+='.';nxt=false;}
        
    }
    cout<<res<<endl;
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

  //  __log__ // Redirect output to test.out
    //__input__ // Read test.in for input

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }

    //__time__ //Runtime
}