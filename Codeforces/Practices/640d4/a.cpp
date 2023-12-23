#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll INF = 1e9;


void solve(int tc){
    string n;
    vector<string> ans;
    cin >> n;
    for (int i=0;i<n.length();i++){
        int t=n.length()-i-1;
        string s (1,n[i]);
        while (t--){
            s+='0';
        }
        if (s[0]!='0')ans.push_back(s);
    }
    int c=ans.size();
    cout << c << endl;
    while (c--){
        cout << ans[c] << " ";
    }
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