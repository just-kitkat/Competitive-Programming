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
bool cmp(vi l, vi r){return l.back()<r.back();}

const int N=82;
int vis[N][N];
int grid[N][N];
int h,w;
vii dx={{0,1},{1,0},{-1,0},{0,-1}};
void dfs(int x, int y){
	//show3(x,y,x);
	if(grid[x][y]==1){
		vis[x][y]++;
	}else grid[x][y]=2;
	for(auto &xz:dx){
		int xx=xz.F,yy=xz.S;
		if(x+xx>=0 and x+xx<h and y+yy>=0 and y+yy<w){
			//show3(x+xx,y+yy,x);
			if(vis[x+xx][y+yy]<2)dfs(x+xx,y+yy);
		}
	}
}
	
signed main()
{
	//FOR(0,5005)p[i]=i;
	cin>>h>>w;
	FOR(0,h){
		JFOR(0,w){
			char t;cin>>t;
			grid[i][j]=t-'0';
		}
	}
	//show("fine");
	//FOR(1,w)if(s[i]==0 and s[i-1]==0)unionSet(i,i-1);
	int ans=0;
	FOR(0,h){
		JFOR(0,w){
			//show3(i,j,j);
			fill(&vis[0][0],&vis[0][0]+N*N,0);
			if(grid[i][j]==0)dfs(i,j);
			for(int x=0;x<h;++x){
				for(int y=0;y<w;++y){
					if(vis[x][y]==2)ans++;
				}
			}
		}
	}
	cout<<ans;
	
	return 0;
}
