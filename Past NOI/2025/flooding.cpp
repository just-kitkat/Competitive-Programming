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

vi p(5005),rrank(5005),setSize(5005,1);
int numSets;
int findSet(int i){return (p[i]==i)?i:(p[i]=findSet(p[i]));}
bool isSameSet(int i,int j){return findSet(i)==findSet(j);}
int sizeOfSet(int i){return setSize[findSet(i)];}
void unionSet(int i, int j){
	if(isSameSet(i,j))return;
	int x=findSet(i), y=findSet(j);
	if(rrank[x]>rrank[y])swap(x,y);
	p[x]=y;
	if(rrank[x]==rrank[y])++rrank[y];
	setSize[y]+=setSize[x];
}

signed main()
{
	FOR(0,5005)p[i]=i;
	int h,w;
	cin>>h>>w;
	vi s(w);
	for(auto &x:s){
		char t;cin>>t;x=t-'0';
	}
	FOR(1,w)if(s[i]==0 and s[i-1]==0)unionSet(i,i-1);
	int ans=0;
	FOR(0,w)if(s[i]==0)ans+=sizeOfSet(i);
	cout<<ans;
	
	return 0;
}
