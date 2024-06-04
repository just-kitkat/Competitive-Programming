// Optimisation attempt
// Programmer: Shadow1

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using str = string; // yay python!

#define i64 int64_t
#define show(x) cerr << (#x) << " = " << (x) << '\n';
#define output_vector(v) for(auto &x : v){cout << x << " ";}cout << '\n';
#define vt vector
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define umap unordered_map
#define uset unordered_set
#define fir first
#define sec second
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// T: O(n^3)
// M : O(n + k log n)

void solve() {
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> prq;
	for(int i=1; i<=n+1; ++i)
		prq.push(i);
	int freq[n+5]={0};
	int nn = n;
	while(nn--) {
		int c, x;
		cin >> c >> x;
        if(x<n+4){
            if(c == 1) 
                freq[x]++;
            if(c == 2 && freq[x] > 0)
                freq[x]--;
            prq.push(x);
            while(!prq.empty()) {
                int k = prq.top();
                if(freq[k] != 0)
                    prq.pop();
                else
                    break;
            }
        }
        int ans = 0;
        if(sz(prq) == 0) 
            ans = 0;
        else
            ans = prq.top() - 1;
		cout << ans << '\n';
	}
}

int main() {
	// freopen("output.txt", "w", stdout);
	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	int T = 1;
	// cin >> T;

	while(T--)
		solve();
	return 0;
}

/* CHECK :
1. COMPARATOR FUNCTION MUST RETURN FALSE WHEN ARGUMENTS ARE EQUAL!!!
2. Overflow! Typecase int64_t on operations if varaibles are int
3. Check array bounds!!!
4. Check array indexing!!!
5. Edge cases. (N==1)!!!
*/
/*
8
1 1
1 2
1 1
1 1
2 1
2 1
2 1
2 1
*/
