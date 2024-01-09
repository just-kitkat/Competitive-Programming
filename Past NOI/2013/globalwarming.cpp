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
#define __log__ { FILE* file = freopen("../../Testcases/test.out", "w", stdout); }
#define __input__ { FILE* file = freopen("../../Testcases/test.in", "r", stdin); }

const int MAX_N = 1e5 + 5;
const ll INF = 1e9;
const double PI = acos(-1);
const auto BEG = std::chrono::high_resolution_clock::now(); //Begining of the program


void solve(int tc){
    int n;
    cin>>n;
    vector<int> a;
    int nn=n;
    int tmp;
    bool pk=0,vy=0;
    a.push_back(0);
    while(nn--){
        cin>>tmp;
        a.push_back(tmp);
    }a.push_back(0);
    unordered_map<int,int>m;
    priority_queue<pair<int,int>>pq;
    for (int i=1;i<n+1;i++)
    if(a[i]>a[i-1] && a[i]>a[i+1])m[a[i]]++;
    else if(a[i]<a[i+1] && a[i]<a[i-1])m[a[i]]--;
    else if(a[i]>a[i-1]&&a[i]==a[i+1] || a[i-1]==a[i]&&a[i]==a[i+1]&&pk)pk=1;
    else if(a[i]<a[i-1]&&a[i]==a[i+1] || a[i-1]==a[i]&&a[i]==a[i+1]&&vy)vy=1;
    else if(pk&&a[i]>a[i+1]){m[a[i]]++;pk=0;}
    else if(vy&&a[i]<a[i+1]){m[a[i]]--;vy=0;}
    else{pk=0;vy=0;}
    
    for(auto [k,v]:m)pq.push({k,v});
    int mx=0,cur=0;
    while(!pq.empty()){
        tmp=pq.top().second;pq.pop();
        cur+=tmp;
        mx=max(mx,cur);
    }
    cout<<mx<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //__log__ // Redirect output to test.out
    //__input__ // Read test.in for input

    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }

    //__time__ //Runtime
}