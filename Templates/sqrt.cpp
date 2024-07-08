/*input
4
1 2 2 3
0 1 3 1
1 1 4 4
0 1 2 2
1 1 2 4
*/
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops,no-stack-protector")
//order_of_key #of elements less than x
// find_by_order kth element
typedef long long int ll;
#define ld double
#define pii pair<ll,ll>
#define f first
#define s second
#define pb push_back
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(double i=1;i<=n;i++)
#define FILL(n,x) memset(n,x,sizeof(n))
#define ALL(_a) _a.begin(),_a.end()
#define sz(x) (int)x.size()
const ll maxn = 5e4 + 5;
const ll maxlg = __lg(maxn) + 2;
const ll INF64 = 4e18;
const int INF = 0x3f3f3f3f;
const ll MOD = ll(1e9 + 7);
//const ld PI=acos(-1);
const ld eps = 1e-9;
#define lowb(x) x&(-x)
#define MNTO(x,y) x=min(x,(__typeof__(x))y)
#define MXTO(x,y) x=max(x,(__typeof__(x))y)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define MP make_pair
ll mult(ll a, ll b) {
    ll res = 0LL;

    while (b) {
        if (b & 1)
            res = (res + a) % MOD;

        a = (a + a) % MOD;
        b >>= 1;
    }

    return res % MOD;
}
ll mypow(ll a, ll b) {
    ll res = 1LL;

    while (b) {
        if (b & 1)
            res = res * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }

    return res;
}
const int blk = 200;
ll arr[maxn];
ll sum[maxn], lzy[maxn];
int32_t main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    assert(n < maxn);
    REP(i, n) cin >> arr[i], sum[i / blk] += arr[i];
    REP(i, n) {
        ll o, l, r, c;
        cin >> o >> l >> r >> c;
        --l;
        --r;

        if (o) {
            ll ans = 0;

            if ((l / blk) != (r / blk)) {
                for (int i = (r / blk) * blk; i <= r; i++)
                    ans += arr[i] + lzy[i / blk];

                for (int i = (l / blk) + 1; i <= (r / blk) - 1; i++)
                    ans += sum[i];

                for (int i = l; i <= (l / blk + 1)*blk - 1; i++)
                    ans += arr[i] + lzy[i / blk];
            } else {
                for (int i = l; i <= r; i++)
                    ans += arr[i] + lzy[i / blk];
            }

            cout << (ans) % (c + 1) << '\n';
        } else {
            if ((l / blk) != (r / blk)) {
                for (int i = (r / blk) * blk; i <= r; i++)
                    arr[i] += c, sum[i / blk] += c;

                for (int i = (l / blk) + 1; i <= (r / blk) - 1; i++)
                    sum[i] += blk * c, lzy[i] += c;

                for (int i = l; i <= (l / blk + 1)*blk - 1; i++)
                    arr[i] += c, sum[i / blk] += c;
            } else {
                for (int i = l; i <= r; i++)
                    arr[i] += c, sum[i / blk] += c;
            }

        }
    }

}