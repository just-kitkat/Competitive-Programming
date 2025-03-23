/*
 * q1.cxx
 * 
 * Copyright 2025 Unknown <noi2023@soctf-pl>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define F first
#define S second
#define pb push_back
#define el '\n'
#define FOR(a,b) for(int i=a;i<b;++i)
#define JFOR(a,b) for(int j=a;j<b;++j)
#define all(x) (x).begin(), (x).end()
#define show(x) cout<<#x<<": "<<x<<el;
#define show3(x,y,z) cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<el;
unordered_map<int,vi>adj;
vi l;
int can=1;
int dfs(int v, int u){
	vi reach;
	int zeros=0;
	for(auto &x:adj[v]){
		if(x==u)continue;
		reach.pb(dfs(x,v));
		zeros+=reach.back()==0;
	}
	reach.pb(l[v-1]);
	sort(all(reach),greater<int>());
	while(reach.size() and reach.back()<=0)reach.pop_back();
	if(reach[0]!=reach.back())can=0;
	if(u==-1 and reach[0]!=1)can=0;
	//show3(reach[0],v,u);
	return reach[0]-1-zeros;
}
		
		
signed main()
{
	int n;
	cin>>n;
	l.resize(n);
	for(auto &x:l)cin>>x;
	int d=1;
	for(auto &x:l)if(x!=1)d++;else break;
	FOR(0,n-1){
		int v,u;
		cin>>v>>u;
		adj[v].pb(u);
		adj[u].pb(v);
	}
	if(d!=n+1)dfs(d,-1); else can=0;
	if(can)cout<<"YES";
	else cout<<"NO";
	return 0;
}
/*
4
1 4 1 1
1 2
2 3
2 4
*/
