#include <bits/stdc++.h>
using namespace std;
#define int __int128_t
#define vi vector<int>
#define F first
#define S second
#define show3(x,y,z) {cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;}
#define el '\n'
#define ii pair<int,int>
class UnionFind{
private:
    vi p,rank,setSize;
    int numSets;
public:
    UnionFind(int N){
        p.assign(N, 0);
        for(int i=0;i<N;++i)p[i]=i;
        rank.assign(N, 0);
        setSize.assign(N,1);
        numSets=N;
    }

    int findSet(int i){return(p[i]==i)?i:(p[i]=findSet(p[i]));}
    bool isSameSet(int i,int j){return findSet(i)==findSet(j);}
    int numDisjointSets(){return numSets;}
    int sizeOfSet(int i){return setSize[findSet(i)];}
    
    void unionSet(int i, int j){
        if(isSameSet(i,j))return;
        int x = findSet(i),y=findSet(j);
        if(rank[x]>rank[y])swap(x,y);
        p[x]=y;
        if(rank[x]==rank[y])++rank[y];
        setSize[y]+=setSize[x];
        --numSets;
    }
};
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    signed n,k;
    cin>>n>>k;
    vector<long long> a(n),ans(k);
    for(auto &x:a)cin>>x;
    priority_queue<ii,vector<ii>,greater<ii>>pq;
    UnionFind uf(n+10);
    vector<ii> b;
    for(int i=0;i<k;++i)pq.push({a[i],i}),b.push_back({a[i],i});
    sort(b.begin(),b.end());
    // cout<<b.size()<<endl;
    for(int i=1;i<k;++i)if(b[i].F==b[i-1].F)uf.unionSet(b[i].S,b[i-1].S);
    int prev=pq.top().S,prevval=1e9+10;
    for(int i=k;i<n;++i){
        auto cur=pq.top();
        pq.pop();
        if(cur.F==prevval)uf.unionSet(cur.S,prev);
        pq.push({cur.F+a[i],cur.S});
        prev=cur.S,prevval=cur.F;
    }
    int farmer=pq.top().S;
    int val=pq.top().F;
    while(!pq.empty() and pq.top().F==val)uf.unionSet(farmer,pq.top().S),pq.pop();
    for(int i=0;i<k;++i)ans[i]=uf.isSameSet(farmer,i);
    cout<<(long long)val<<endl;
    for(auto &x:ans)cout<<x;

}