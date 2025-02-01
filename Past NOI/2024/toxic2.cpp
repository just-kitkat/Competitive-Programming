// #include "toxic.h"
#include <bits/stdc++.h>
using namespace std;
#define int long long

constexpr int maxn {1000};
constexpr int maxk {1000};
constexpr int maxq {2000};

int n;
char ans[maxn + 5];

int queries=0;
bool answered=false;

void WA(const char* s) {
	printf("%s\n", s);
	fflush(stdout);
	exit(0);
}

std::vector<int> query_machine(std::vector<int> samples){
	if (answered) {
		WA("Incorrect. Called query_machine after answer_type\n");
	}
	
	++queries;
	
	if (samples.size() > maxk) {
		WA("Incorrect. Too many samples passed to query_machine\n");
	}
	
	vector<int> cur;
	for (int i: samples) {
		if (i < 0 || i >= n) {
			WA("Incorrect. Invalid species number passed to query_machine\n");
		}
		cur.push_back(i);
	}
	
	vector<int> res;
	while (true) {
		vector<int> nw;
		for (int i = 0; i < cur.size(); ++i) {
			bool rem = false;
			if (i != 0 && ans[cur[i]] == 'R' && ans[cur[i - 1]] == 'T') rem = true;
			if (i != cur.size() - 1 && ans[cur[i]] == 'R' && ans[cur[i + 1]] == 'T') rem = true;
			if (!rem) nw.push_back(cur[i]);
		}
		
		if (cur.size() == nw.size()) {
			if (res.empty()) res.push_back(nw.size());
			break;
		}
		res.push_back(nw.size());
		
		swap(cur, nw);
	}
	
	return res;
}

void answer_type(std::vector<char> v){
	if (answered) {
		WA("Incorrect. Called answer_type twice\n");
	}
	
	answered=true;
	if (v.size() != n) {
		WA("Incorrect number of elements returned\n");
	}
	
	for (int i = 0; i < n; ++i) {
		if (v[i] != ans[i]) {
			WA("Incorrect value returned\n");
		}
	}
}
vector<int> vis;
vector<char>anss;
unordered_map<int,vector<int>>pos;
void dfs(int v){
    anss[v]='T';
    vis[v]=1;
    for(auto &x:pos[v]){
        if(vis[x])continue;
        dfs(x);
    }
}
void determine_type(int n) {
	// std::vector<int> res = query_machine({1, 0, 2, 1});
	// answer_type({'T', 'R', 'R'});
    // 0 is toxic
    vis.resize(1001,0);
    anss.resize(n,'R');
    pos.clear();
    for(int i=1;i<n;++i){
        // test i-1 and i
        auto res = query_machine({i-1, i, i});
        // for(auto &x:res)cout<<x<<' ';cout<<endl;
        if(res.size()==2){ // i-1 is toxic
            anss[i-1]='T';
        }else if(res[0]==2){ // i is toxic
            anss[i]='T';
        }else{
            // res = {3} // all are either R or T
            pos[i-1].push_back(i);
            pos[i].push_back(i-1);
        }
    }
    for(int i=n-1;i>=0;--i){
        if(anss[i]=='T')dfs(i);
    }
    // for(auto &x:anss)cout<<x<<' ';cout<<endl;
    answer_type(anss);
}

/*

res = 1
R T
T R

res = 2
T T
R R

res = 1
R T R
T T R
R T T

res = 2
T R R
R R T

res = 3
T T T
R R R
*/

signed main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf(" %c", &ans[i]);
	}
	
	determine_type(n);
	
	if(!answered){
		WA("Incorrect. Did not call answer_type\n");
	}
	
	printf("Correct. %d queries used\n", queries);
	fflush(stdout);
}
