// Author: JustKitkat

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
    int n,q;
    cin>>n>>q;
    int a[n];
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        if (i==0)a[i]=x;
        else a[i]=a[i-1]+x;
    }
    for(int i=0;i<q;i++){
        int l,r,k;
        cin>>l>>r>>k;
        int a1,a2,a3;
        l-2>=0?a1=a[l-2]:a1=0;
        a2=(r-l+1)*k;
        r!=n?a3=a[n-1]-a[r-1]:a3=0;
        int t=a1+a2+a3;
        cout<<(t&1?"YES":"NO")<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    __log__ // Redirect output to test.out
    __input__ // Read test.in for input

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }

    //__time__ //Runtime
}