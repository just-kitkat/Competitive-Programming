// #include "squarerect.h"
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el "\n"
#define arr array
#define ll long long
#define ld long double
#define ii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vii vector<ii>
#define vllll vector<pll>
#define umap unordered_map
#define uset unordered_set
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(a) (a).begin(), (a).end()
#define FOR(a,b) for(int i=a;i<b;++i)
#define DFOR(a,b) for(int i=a;i>=b;--i)
#define JFOR(a,b) for(int j=a;j<b;++j)
#define DJFOR(a,b) for(int j=a;j>=b;--j)
#define show(x) cerr << #x << " is " << x << endl;
#define show2(x,y) cerr << #x << " is " << x << " " << #y << " is " << y << endl;
#define show3(x,y,z) cerr << #x << " is " << x << " " << #y << " is " << y << " " << #z << " is " << z << endl;
#define show_vec(a) { for(auto &x:a)cerr<<x<<' '; cerr<<endl; }
#define discretize(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

#define __time__ { auto duration = chrono::duration<double>( /* Show runtime */ \
chrono::high_resolution_clock::now() - BEG); cout<<"Time: "<<duration.count()<<endl;}

// PBDS -> initialise using `ordered_set s;` -> change to greater<int> for reversed order.
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// #define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAX_N = 1e5 + 5;
const ll INF = 1e15;
const ll MOD = 1e9+7;
const double PI = acos(-1);
const auto BEG = std::chrono::high_resolution_clock::now(); //Begining of the program

static int T;
static int N, Q, X1, X2, Y1, Y2, q;

bool inside_shape(int X, int Y) {
    // show2(X,Y);
	q++;
	if (0 and q > Q) {
		printf("Wrong Answer. Used too many queries.\n");
		exit(0);
	}
	if (X <= 0 || X > N || Y <= 0 || Y > N) {
		printf("Wrong Answer. Query parameters out of range.\n");
		exit(0);
	}
	return (X >= X1 && X <= X2 && Y >= Y1 && Y <= Y2);
}

int memo[101][101];
bool qu(int X, int Y){
    if(memo[X][Y]==-1) return memo[X][Y]=inside_shape(X,Y);
    return memo[X][Y];
}
bool am_i_square(signed N, signed Q) {
    fill(&memo[0][0],&memo[0][0]+101*101,-1);
    vi queries;
    int partition = ceil(sqrt((ld)(Q==40?25:4)/100 * (N*N)));
    int p=partition;
    while(p<=N) queries.pb(p), p+=partition;
    if(p<N+partition)queries.pb(N);

    // search on rows and cols in queries
    // start with rows
    int rowStart=200, rowEnd=-1, colStart=200, colEnd=-1;
    for(auto &y:queries){ // col
        for(auto &x:queries){ // row
            if(qu(x,y)) 
                rowStart=min(rowStart, y), rowEnd=max(rowEnd, y),
                colStart=min(colStart, x), colEnd=max(colEnd, x);
        }
    }
    // dbg(rowStart, rowEnd, colStart, colEnd);
    if(rowStart==200 or rowEnd==-1 or colStart==200 or colEnd==-1)return 0;
    // binary search on rows
    // left
    int lo=max(1ll,rowStart-partition), hi=rowStart;
    while(lo<hi){
        int mid=(lo+hi)/2;
        if(!qu(colStart, mid)){ // not in shape
            lo=mid+1;
        }else hi=mid;
    }
    rowStart=lo;
    // right
    lo=rowEnd, hi=min((ll)N,rowEnd+partition);
    while(lo<hi){
        int mid=(lo+hi+1)/2;
        if(!qu(colStart, mid)){ // not in shape
            hi=mid-1;
        }else lo=mid;
    }
    rowEnd=lo;

    // binary search on cols
    // down
    lo=max(1ll,colStart-partition), hi=colStart;
    while(lo<hi){
        int mid=(lo+hi)/2;
        if(!qu(mid, rowStart)){ // not in shape
            lo=mid+1;
        }else hi=mid;
    }
    colStart=lo;
    // up
    lo=colEnd, hi=min((ll)N,colEnd+partition);
    while(lo<hi){
        int mid=(lo+hi+1)/2;
        if(!qu(mid, rowStart)){ // not in shape
            hi=mid-1;
        }else lo=mid;
    }
    colEnd=lo;
    
    return (rowEnd-rowStart == colEnd-colStart);
}


signed main() {
	if (scanf("%d%d%d", &T, &N, &Q) != 3) {
		printf("Input file invalid.\n");
		return 0;
	}
	int mxq = 0;
	for (int i = 0; i < T; i++) {
		if (scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2) != 4) {
			printf("Input file invalid.\n");
			return 0;
		}
		q = 0;
		bool user_ans = am_i_square(N, Q);
        show(q);
		bool act_ans = (Y2 - Y1) == (X2 - X1);
		if (user_ans != act_ans) {
			printf("Wrong Answer.\n");
			exit(0);
		}
		mxq = max(mxq, q);
	}
	printf("Correct. Used %d out of %d queries.\n", mxq, Q);
    return 0;
}

/*

5 100 50
20 20 40 40
25 25 45 45
27 27 87 87
20 40 80 90
20 23 83 93


*/