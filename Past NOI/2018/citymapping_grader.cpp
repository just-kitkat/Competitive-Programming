// #include "citymapping.h"
#include <bits/stdc++.h>
using namespace std;

static int N, Q, S, twok[1005][11], depth[1005], curQ, target = 6500;
static long long dist[1005];
static vector< pair<int, int> > adjlist[1005];
static vector< pair< pair<int, int>, int > > edgelist, user_edgelist;

static void dfs(int x, int p, long long d, int dep) {
	dist[x] = d;
	depth[x] = dep;
	twok[x][0] = p;
	for (int i = 1; i <= 10; i++) {
		if (twok[x][i - 1] == -1) break;
		twok[x][i] = twok[twok[x][i - 1]][i - 1];
	}
	for (int i = 0; i < (int)adjlist[x].size(); i++) {
		if (adjlist[x][i].first == p) continue;
		dfs(adjlist[x][i].first, x, d + adjlist[x][i].second, dep + 1);
	}
}

static int lca(int x, int y) {
	if (depth[x] > depth[y]) swap(x, y);
	int dd = depth[y] - depth[x];
	for (int i = 0; i <= 10; i++) if (dd & (1 << i)) y = twok[y][i];
	if (x == y) return x;
	for (int i = 10; i >= 0; i--) {
		if (twok[x][i] != twok[y][i]) {
			x = twok[x][i];
			y = twok[y][i];
		}
	}
	return twok[x][0];
}
int cnt=0;
long long get_distance(int X, int Y) {
    cnt++;
	if (X <= 0 || X > N || Y <= 0 || Y > N) {
		printf("Score: 0.00%%\nWrong Answer: get_distance() arguments out of range.\n");
		exit(0);
	}
	curQ++;
	// if (curQ > Q) {
	// 	printf("Score: 0.00%%\nWrong Answer: Too many calls to get_distance().\n");
	// 	exit(0);
	// }
	return dist[X-1] + dist[Y-1] - dist[lca(X-1, Y-1)] * 2;
}

mt19937_64 rnd(31);
#define ll long long
#define show(x) cout<<#x<<": "<<x<<endl;
#define show_vec(v) {for(auto &x:v)cout<<x<<' ';cout<<endl;}
#define show_vecp(v) {for(auto &x:v)cout<<x.first<<','<<x.second<<" | ";cout<<endl;}
int rng(int x, int y){return rnd()%(y-x+1)+x;}
vector<int>gA,gB,gW;
void discover(int root, vector<int>&subtree){
    // base case: subtree empty
    if(subtree.size()<=1) return;

    // get random root
    root=subtree[rng(1,subtree.size())-1];
    subtree.erase(find(subtree.begin(),subtree.end(),root));

    show(root);
    // show_vec(subtree);

    // get distances to all nodes
    vector<pair<ll,int>>dist;
    for(auto &x:subtree)dist.push_back({get_distance(root,x),x});

    // get shortest node -- child (this node is adj to root)
    sort(dist.begin(),dist.end());
    int child = dist[0].second;
    gA.push_back(child), gB.push_back(root), gW.push_back(dist[0].first);

    // get all distances from child
    vector<pair<ll,int>>dist2;
    unordered_map<int,ll>distFromChild;
    for(auto &x:subtree)
        if(x!=child)
            dist2.push_back({get_distance(child,x),x}),
            distFromChild[x]=dist2.back().first;

    // determine subtree1
    vector<int> subtree1;
    vector<pair<ll,int>>others;
    for(auto &x:dist){
        if(x.second!=child){
            if(x.first > distFromChild[x.second]) subtree1.push_back(x.second);
            else others.push_back(x);
        }
    }
    subtree1.push_back(child);
    discover(1, subtree1);

    // determine subtree2 (all in subtree n subtree1') ( n rep set intersection )
    if(others.size()){
        int child2=others[0].second;
        gA.push_back(child2), gB.push_back(root), gW.push_back(others[0].first);
        if(others.size()==1)return;
        // get all distances
        unordered_map<int,ll>distFromChild2;
        vector<int> subtree2;
        vector<pair<ll,int>>subtree3;
        for(auto &x:others)
            if(x.second!=child2)distFromChild2[x.second]=get_distance(child2,x.second);
        for(auto &x:dist){
            if(distFromChild2.count(x.second)){
                if(x.first>distFromChild2[x.second])subtree2.push_back(x.second);
                else subtree3.push_back(x);
            }
        }
        subtree2.push_back(child2);
        if(subtree3.size()){
            sort(subtree3.begin(),subtree3.end());
            int child3=subtree3[0].second;
            gA.push_back(child3), gB.push_back(root), gW.push_back(subtree3[0].first);
        }
        vector<int> realsubtree3;
        for(auto &x:subtree3)realsubtree3.push_back(x.second);
        discover(1, subtree2);
        discover(1, realsubtree3);
        show("e");
        show_vec(subtree1);
        show_vec(subtree2);
        show_vec(realsubtree3);
    }


}

/*
5 10000 5
1 2 1
2 3 1
3 4 1
4 5 1
*/

void find_roads(int N, int Q, int A[], int B[], int W[]){
    gA.clear(),gB.clear(),gW.clear();
    vector<int>r;
    int root=1;
    vector<int>subtree;
    for(int i=1;i<=N;++i)r.push_back(i);
    int randomNode=rng(1,N);
    discover(randomNode, r);
    for(int i=0;i<N-1;++i)A[i]=gA[i],B[i]=gB[i],W[i]=gW[i];
    // for(int i=0;i<N-1;++i)cout<<A[i]<<' ';cout<<endl;
}

int main() {
	scanf("%d%d%d", &N, &Q, &S);
	for (int i = 0; i < N - 1; i++) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		a--;
		b--;
		adjlist[a].push_back(make_pair(b, w));
		adjlist[b].push_back(make_pair(a, w));
		edgelist.push_back(make_pair(make_pair(min(a, b) + 1, max(a, b) + 1), w));
	}
	sort(edgelist.begin(), edgelist.end());
	memset(twok, -1, sizeof(twok));
	dfs(0, -1, 0, 0);
	int A[N-1], B[N-1], W[N-1];
	memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));
	memset(W, 0, sizeof(W));
	find_roads(N, Q, A, B, W);
	for (int i = 0; i < N-1; i++) user_edgelist.push_back(make_pair(make_pair(min(A[i], B[i]), max(A[i], B[i])), W[i]));
	sort(user_edgelist.begin(), user_edgelist.end());
    for(auto &x:user_edgelist)cout<<x.first.first<<','<<x.first.second<<": "<<x.second<<endl;
    cout<<endl;
    for(auto &x:edgelist)cout<<x.first.first<<','<<x.first.second<<": "<<x.second<<endl;
    show(cnt);
	if (edgelist != user_edgelist) {
		printf("Score: 0.00%%\nWrong Answer: Reported list of edges differ from actual.\n");
		exit(0);
	}
	if (S <= 4) {
		printf("Score: 100.00%%\nCorrect: %d out of %d queries used.\n", curQ, Q);
		exit(0);
	} else {
		if (curQ <= target) printf("Score: 100.00%%\nCorrect: %d out of %d queries used.\n", curQ, Q);
		else if (curQ >= 12000) printf("Score: %.2lf%%\nCorrect: %d out of %d queries used.\n", (10.0-10.0*((double)(curQ - 12000) / 13000)) / 43 * 100, curQ, Q);
		else printf("Score: %.2lf%%\nCorrect: %d out of %d queries used.\n", (40.0-30.0*((double)(curQ - target) / (12000 - target))) / 43 * 100, curQ, Q);
	}
}
