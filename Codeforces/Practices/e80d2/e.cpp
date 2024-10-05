// Author: JustKitkat
// Status: AC

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el "\n"
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first
#define S second
#define FOR(a,b) for(auto i=a;i<b;++i)

struct node{
    int Start, End, Midpoint;
    int val;
    node *l, *r;

    node(int s, int e){
        Start = s;
        End = e;
        Midpoint = (Start + End)/2;

        if(Start == End){
            val = 0;
            return;
        }

        l = new node(Start, Midpoint);
        r = new node(Midpoint + 1, End);
		
        val = 0;
    }

    int query(int ql, int qr){
        if(ql <= Start && End <= qr){
            return val;
        }
        if(End < ql || qr < Start){
            return 0; //LLONG_MAX if taking min and vice versa, use 0 if sum
        }
        return l->query(ql, qr) + r->query(ql, qr);
    }

    void update(int qx, int qv){   

        if(Start == End){
            val = qv;
            return;
        }

        if(qx <= Midpoint) l->update(qx, qv);
        else r->update(qx, qv);

        val = l->val + r->val;

    }

};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n=0, q=0, p;
    cin>>n>>q;
    p=q;
    node st(0LL,n+q);
    vi qq(q), pos(n+1);
    vii ans(n+1);
    FOR(1,n+1) ans[i].F=i, pos[i]=q+i-1;
    for(auto &x:qq) cin>>x, ans[x].F=1;

    for(auto &x:qq){
        auto idx = pos[x];
        ans[x].S=max(ans[x].S, -q+idx+st.query(idx,n+q)+1);
        st.update(idx,1), pos[x]=p-1, p--;
    }
    FOR(1,n+1)ans[i].S=max(ans[i].S, -q+pos[i]+st.query(pos[i],n+q)+1);

    ans[0].F=-1;
    for(auto &[a,b]:ans)if(a!=-1)cout<<a<<' '<<b<<el;
}
