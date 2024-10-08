#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Simple Segment Tree (no lazy prop/nodes)
const int N = 1e5;  // limit for array size
ll n;  // array size
ll t[2 * N]={0};

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = min(t[i<<1], t[i<<1|1]);
}

void modify(int p, ll value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = min(t[p], t[p^1]);
}

int query(int l, int r) { 
  ll res = LLONG_MAX;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = min(res,t[l++]);
    if (r&1) res = min(res,t[--r]);
  }
  return res;
}


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


int main(){
    return 0;
}