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





int main(){
    return 0;
}