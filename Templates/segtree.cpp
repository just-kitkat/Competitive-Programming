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


// ALL IN ONE SEGTREE
// typedef long long ll;
struct node3 {
    int s, e;
    ll mn, mx, sum;
    bool lset;
    ll add_val, set_val;
    node3 *l, *r;
    node3 (int _s, int _e, int A[] = NULL): s(_s), e(_e), mn(0), mx(0), sum(0), lset(0), add_val(0), set_val(0), l(NULL), r(NULL) {
        if (A == NULL) return;
        if (s == e) mn = mx = sum = A[s];
        else {
            l = new node3(s, (s+e)>>1, A), r = new node3((s+e+2)>>1, e, A);
            combine();
        }
    }
    void create_children() {
        if (s == e) return;
        if (l != NULL) return;
        int m = (s+e)>>1;
        l = new node3(s, m);
        r = new node3(m+1, e);
    }
    void self_set(ll v) {
        lset = 1;
        mn = mx = set_val = v;
        sum = v * (e-s+1);
        add_val = 0;
    }
    void self_add(ll v) {
        if (lset) { self_set(v + set_val); return; }
        mn += v, mx += v, add_val += v;
        sum += v*(e-s+1);
    }
    void lazy_propagate() {
        if (s == e) return;
        if (lset) {
            l->self_set(set_val), r->self_set(set_val);
            lset = set_val = 0;
        }   
        if (add_val != 0) {
            l->self_add(add_val), r->self_add(add_val);
            add_val = 0;
        }
    }
    void combine() {
        if (l == NULL) return;
        sum = l->sum + r->sum;
        mn = min(l->mn, r->mn);
        mx = max(l->mx, r->mx);
    }
    void add(int x, int y, ll v) {
        if (s == x && e == y) { self_add(v); return; }
        int m = (s+e)>>1;
        create_children(); lazy_propagate();
        if (x <= m) l->add(x, min(y, m), v);
        if (y > m) r->add(max(x, m+1), y, v);
        combine();
    }
    void set(int x, int y, ll v) {
        if (s == x && e == y) { self_set(v); return; }
        int m = (s+e)>>1;
        create_children(); lazy_propagate();
        if (x <= m) l->set(x, min(y, m), v);
        if (y > m) r->set(max(x, m+1), y, v);
        combine();
    }
    ll range_sum(int x, int y) {
        if (s == x && e == y) return sum;
        if (l == NULL || lset) return (sum / (e-s+1)) * (y-x+1);
        int m = (s+e)>>1;
        lazy_propagate();
        if (y <= m) return l->range_sum(x, y);
        if (x > m) return r->range_sum(x, y);
        return l->range_sum(x, m) + r->range_sum(m+1, y);
    }
    ll range_min(int x, int y) {
        if (s == x && e == y) return mn;
        if (l == NULL || lset) return mn;
        int m = (s+e)>>1;
        lazy_propagate();
        if (y <= m) return l->range_min(x, y);
        if (x > m) return r->range_min(x, y);
        return min(l->range_min(x, m), r->range_min(m+1, y));
    }
    ll range_max(int x, int y) {
        if (s == x && e == y) return mx;
        if (l == NULL || lset) return mx;
        int m = (s+e)>>1;
        lazy_propagate();
        if (y <= m) return l->range_max(x, y);
        if (x > m) return r->range_max(x, y);
        return max(l->range_max(x, m), r->range_max(m+1, y));
    }
    ~node3() {
        if (l != NULL) delete l;
        if (r != NULL) delete r;
    }
} *root;


// root = new node(0, N-1, array); //creates a segment tree with elements 0 to N - 1. The array parameter is optional.
// root = new node(0, 1000000000); //this tree supports lazy node creation and propagation too, declare as much as you like :)


// root->add(0, 5000, 3);    //add 3 to range [0, 5000]
// root->add(3000, 9000, -2); //minus 2 to range [3000, 9000]
// root->set(7000, 10000, 5);    //set range [7000, 10000] to 5

// /* at this point, 0 to 2999 is 3, 3000 to 5000 is 1, 5001 to 6999 is -2, 7000 to 10000 is 5 */
// root->range_max(0, 10000);    //returns 5
// root->range_min(0, 10000);    //returns -2
// root->range_sum(0, 10000);    //returns 22008


int main(){
    return 0;
}


/*
// RURQ lazy prop + lazy node
struct node {
    node *l, *r;
    int val, s, m, e, lazyadd;
    node(int _s, int _e): s(_s), e(_e), m((_s+_e)/2), val(0), lazyadd(0), l(NULL), r(NULL) {}
    int value() { //returns the value of the current node after lazy propagating
        if (s == e) return val + lazyadd;
        if (lazyadd == 0) return val;
        val += lazyadd;
        if (l == NULL) l = new node(s, m);
        if (r == NULL) r = new node(m+1, e);
        l->lazyadd += lazyadd, r->lazyadd += lazyadd;
        lazyadd = 0;
        return val;
    }
    void add(int x, int y, int v) {
        if (s == x && e == y) lazyadd += v;
        else {
            if (x > m) {
                if (r == NULL) r = new node(m+1, e);
                r->add(x, y, v);
            }
            else if (y <= m) {
                if (l == NULL) l = new node(s, m);
                l->add(x, y, v);
            }
            else {
                if (r == NULL) r = new node(m+1, e);
                if (l == NULL) l = new node(s, m);
                l->add(x, m, v), r->add(m+1, y, v);
            }
            if (l != NULL && r != NULL) val = min(l->value(), r->value()); //Change here for max
            else if (l == NULL) val = r->value();
            else if (r == NULL) val = l->value();
        }
    }
    int query(int x, int y) {
        value();
        if (s == x && e == y) return value();
        if (x > m) return (r==NULL)? 0:r->query(x, y);
        if (y <= m) return (l==NULL)? 0:l->query(x, y);
        if (l == NULL && r != NULL) return r->query(m+1, y);
        if (l != NULL && r == NULL) return l->query(x, m);
        if (l != NULL && r != NULL) return min(l->query(x, m),r->query(m+1, y)); //Change here for max
        return 0;
    }
};
// inclusive and employs lazy node creation. supports negative 'ranges', defaults to 0. 
node root(-1000000000, 1000000000);
// Change the 'default' to 1 -> Lazy propagated O(log R)
add(-1000000000, 1000000000, 1); 
add(0, 5, -2); //adds -2 to (0 to 5) inclusive
query(5, 8); //first must be lower than second,  returns minimum of (5 to 8) inclusive
*/