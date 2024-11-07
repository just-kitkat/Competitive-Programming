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

// Seg tree with lazy prop and lazy node creation
struct node2{
	node2 *left, *right;
	int S, E, val, lazy;
	node2(int _s, int _e) : S(_s), E(_e){
			left = right = nullptr;
			val = 0;
			lazy = 0;
	}

	void prop(){
		if(S == E) return;
		int M = (S+E) >> 1;
		if(left == nullptr){
			left = new node2(S, M);
			right = new node2(M+1, E);
		}
		if(lazy != 0){
			left->val += lazy*(M-S+1);
			left->lazy += lazy;
			right->val += lazy*(E-M);
			right->lazy += lazy;
			lazy = 0;
		}
	}

	int qry(int l, int r){
		if (l > E || r < S) return 0;
		if(l <= S && E <= r) return val;
		prop();
		return left->qry(l, r) + right->qry(l, r);
	}
	
	void upd(int l, int r, int v){
		if(l > E || r < S) return;
		if(l <= S && E <= r){
			val += v*(E-S+1);
			lazy += v;
			return;
		}
		prop();
		left->upd(l, r, v);
		right->upd(l, r, v);
		val = left->val + right->val;
	}
};


int main(){
    return 0;
}