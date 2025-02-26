#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define show3(x,y,z) cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
int n,k;
const int INF=1005;
vector<pair<int,int>>a;
#define ld long double
ld memo[105][1005][105];
ld dp(int pos, int collab, int left){
    if(pos==n and left>0)return 1e18;
    if(pos==n or left==0)return 0;
    if(memo[pos][collab][left]!=-1)return memo[pos][collab][left];
    ld res=2e18;
    // take
    // dont take collab
    res=min(res,dp(pos+1,collab,left-1)+(ld)a[pos].second/(ld)collab);
    //take collab
    if(a[pos].first!=INF)
        res=min(res,dp(pos+1,collab+1,left-1)+(ld)a[pos].first/(ld)collab);

    // dont take
    res=min(res,dp(pos+1,collab,left));
    cout<<"pos: "<<pos<<endl;
    // cout<<a[pos].first<<' '<<a[pos].second<<endl;
    show3(res,collab,left);
    return memo[pos][collab][left]=res;

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;
    fill(&memo[0][0][0],&memo[0][0][0]+105*1005*105,-1);
    a.resize(n);
    int alla=1;
    for(auto &x:a){
        cin>>x.second>>x.first;
        if(x.first==-1)x.first=INF;
        if(x.first!=INF)alla=0;
    }
    sort(a.begin(),a.end());
    ld ans=0;
    if(alla){
        for(auto &x:a)swap(x.first,x.second);
        sort(a.begin(),a.end());
        for(int i=0;i<k;++i)ans+=a[i].first;
    }
    else{
        ans=dp(0,1,k);
    }
    cout<<setprecision(20)<<ans;


}

/*

3 2
9 -1
1 5
6 6

*/
