#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll INF = 1e9;


void solve(int tc){
    int n;
    int a,b,c;
    cin >> a >> b >> c;
    if (a+b==c)cout<<"+";
    else cout<<"-";
    cout<<endl;
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }
}   