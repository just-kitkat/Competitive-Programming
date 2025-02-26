#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define FOR(a,b) for(int i=a;i<b;++i)
#define ii pair<int,int>


struct node{
    int s,e,mn,mx;
    int sum; 
    bool lset;
    int add_val,set_val;
    node *l,*r;
    node(int ss,int ee):s(ss),e(ee),mn(0),mx(0),sum(0),lset(0),add_val(0),set_val(0),l(NULL),r(NULL){
        return;
    }
    void create_children(){
        if(s==e)return;
        if(l!=NULL)return;
        int m=(s+e)>>1;
        l=new node(s,m);
        r=new node(m+1,e);
    }
    void self_set(int v){
        lset=1;
        mn=mx=set_val=v;
        sum=v*(e-s+1);
        add_val=0;
    }
    void lazy_propagate(){
        if(s==e)return;
        if(lset){
            l->self_set(set_val),r->self_set(set_val);
            lset=set_val=0;
        }
    }
    void combine(){
        if(l==NULL)return;
        sum=l->sum+r->sum;
        mn=min(l->mn,r->mn);
        mx=max(l->mx,r->mx);
    }
    void set(int x, int y, int v){
        if(s==x and e==y){self_set(v);return;}
        int m=(s+e)>>1;
        create_children();lazy_propagate();
        if(x<=m)l->set(x,min(y,m),v);
        if(y>m)r->set(max(x,m+1),y,v);
        combine();
    }
    int range_sum(int x,int y){
        if(s==x and e==y)return sum;
        if(l==NULL or lset)return (sum/(e-s+1))*(y-x+1);
        int m=(s+e)>>1;
        lazy_propagate();
        if(y<=m)return l->range_sum(x,y);
        if(x>m)return r->range_sum(x,y);
        return l->range_sum(x,m)+r->range_sum(m+1,y);
    }
    ~node(){
        if(l!=NULL)delete l;
        if(r!=NULL)delete r;
    }
};
bool byCost(vi l,vi r){return l[2]<r[2];}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int h,w,k;
    cin>>h>>w>>k;
    vector<vi>a(h,vi(3));
    int mincost=LLONG_MAX;
    int lEqualR=1;
    for(auto &x:a){
        cin>>x[0]>>x[1]>>x[2]; //l,r,c
        if(x[0]!=x[1])lEqualR=0;
        mincost=min(mincost,x[2]);
    }
    if(k==0 and mincost!=0){ // st 1, none can be moved
        node *st=new node(0,w+5);
        for(auto &x:a)st->set(x[0],x[1],1);
        cout<<w-st->range_sum(1,w);
    }else if(lEqualR){ // width of all walls is 1
        // for each range store a cost
        unordered_map<int,int>m;
        for(auto &x:a)m[x[0]]+=x[2];
        vector<ii>aa;
        for(auto &x:m)aa.push_back({x.second,x.first});
        sort(aa.begin(),aa.end(),greater<ii>());
        while(aa.size() and aa.back().first<=k){
            k-=aa.back().first;
            aa.pop_back();
        }
        cout<<w-max((int)1,(int)aa.size());

    }else 
    if(h<=20 and w<=20){
        int ans=0;
        for(int i=0;i<(1<<h);++i){
            vector<vi> use, notUsed;
            int cost=0;
            for(int j=0;j<h;++j){
                if(i&(1<<j)){
                    use.push_back(a[j]);
                    cost+=a[j][2];
                }else notUsed.push_back(a[j]);
            }
            // cout<<"ddd\n";
            // for(auto &x:use)cout<<x[0]<<' ';cout<<endl;
            // for(auto &x:notUsed)cout<<x[0]<<' ';cout<<endl;
            if(cost>k)continue;
            // now try the walls in use
            int largestWall=0;
            for(auto &x:use)largestWall=max(largestWall,x[1]-x[0]+1);
            // try placing from pos=1...w
            if(largestWall>0){
                for(int pos=1;pos<=w-largestWall+1;++pos){
                    node *st=new node(0,2005); // set all to 0 instead for MLE
                    for(auto &xx:notUsed)st->set(xx[0],xx[1],1);
                    st->set(pos,pos+largestWall-1,1);
                    ans=max(ans,w-st->range_sum(1,w));
                }
            }else{
                node *st=new node(0,2005); // set instead
                for(auto &xx:notUsed)st->set(xx[0],xx[1],1);
                ans=max(ans,w-st->range_sum(1,w));
            }
        }
        cout<<ans;

    }else cout<<1;
    // else nahhhh

    return 0;

}

/*

(DONE) st 1: budget = 0, cannot move walls, just iterate and check
(DONE) st 2: l == r, greedily take lowest cost and move them to positions of locked walls
st 3: h,w <= 18, try to unlock all subsets of walls. place the walls using dp?
st 4: h,w <= 100, k<=2000, 10,000,000 idkkk
st 7: walls are all the same length. idkkk
for each wall, store how much of it is being overlapped


*/