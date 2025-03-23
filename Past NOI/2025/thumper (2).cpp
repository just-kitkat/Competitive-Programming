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
vi rabbits[2002][8];
signed main()
{
	int n,m;
	cin>>n>>m;
	vii a(n);
	for(auto &x:a)cin>>x.F>>x.S; // {row, col}
	vi t(m);
	for(auto &x:t)cin>>x;
	// [i][idx]
	// idx=0 top left  =1 top  =2 top right
	// idx=3 right     =4 bottom right
	// idx=5 bottom    =6 bottom left
	// idx=7 left
	FOR(0,n){
		JFOR(0,n){
			//show3(i,j,i);
			if(i==j)continue;
			int idx;
			if(abs(a[i].F-a[j].F) == abs(a[i].S-a[j].S)){ //diag
				if(a[j].F < a[i].F){
					if(a[j].S < a[i].S) idx=0; // top left
					else idx=2; // top right
				}else{
					if(a[j].S < a[i].S) idx=6; // bottom left
					else idx=4; // bottom right
				}
			}
			else if(abs(a[i].F-a[j].F) < abs(a[i].S-a[j].S)){ // more col
				if(a[j].S < a[i].S) idx=7; // left
				else idx=3; // right
			}
			else if(abs(a[i].F-a[j].F) > abs(a[i].S-a[j].S)){ // more row
				if(a[j].F < a[i].F) idx=1; // top
				else idx=5; // bottom
			}
			else assert(0);
			//show3(i,j,idx);
			rabbits[i][idx].pb(j);
		}
	}
	//show("ee");
	unordered_map<int,int>tp;
	for(auto &x:t)tp[x]++;
	for(auto &[rab,cnt]:tp){
		int x=rab-1;
		for(auto &xx:rabbits[x][0])a[xx].F-=cnt, a[xx].S-=cnt;
		for(auto &xx:rabbits[x][1])a[xx].F-=2*cnt;
		for(auto &xx:rabbits[x][2])a[xx].F-=cnt,a[xx].S+=cnt;
		for(auto &xx:rabbits[x][3])a[xx].S+=2*cnt;
		for(auto &xx:rabbits[x][4])a[xx].F+=cnt, a[xx].S+=cnt;
		for(auto &xx:rabbits[x][5])a[xx].F+=2*cnt;
		for(auto &xx:rabbits[x][6])a[xx].F+=cnt, a[xx].S-=cnt;
		for(auto &xx:rabbits[x][7])a[xx].S-=2*cnt;
	}
	for(auto &x:a)cout<<x.F<<' '<<x.S<<el;
	return 0;
}
