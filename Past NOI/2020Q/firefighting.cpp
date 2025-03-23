#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define ii pair<int,int>
#define FOR(a,b) for(int i=a;i<b;++i)

unordered_map<int,vector<ii>>adj;
unordered_set<int> ans;
vector<ii> dist;
vi fire;
int n,k;
void dfs(int v, int u){
    if(adj[v].size()==1 and u!=-1){
        dist[v]={0,0};
        return;
    }
    int low=0;
    for(auto &[x,w]:adj[v]){
        if(x==u)continue;
        dfs(x,v);
        fire[v]=min(fire[x]+w,fire[v]);
        if(dist[x].S+w>k and !dist[x].F){
            ans.insert(x);
            fire[v]=min(fire[v],w);
        }else if(!dist[x].F)low=max(low,dist[x].S+w);
    }
    if(low+fire[v]>k)dist[v]={0,low};
    else dist[v]={1,low};
    if(u==-1 and dist[v].F==0)ans.insert(v);
}
signed main(){
    cin>>n>>k;
    FOR(0,n-1){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    // for(auto &x:adj){
    //     cout<<x.F<<": ";
    //     for(auto &xx:x.S)cout<<xx.F<<' ';cout<<endl;
    // }
    dist.resize(n+5);
    fire.resize(n+5,1e9+5);
    dfs(1,-1);
    // int ind=0;
    // for(auto &x:dist)cout<<ind++<<": "<<x.F<<", "<<x.S<<endl;
    cout<<ans.size()<<endl;
    for(auto &x:ans)cout<<x<<' ';

}