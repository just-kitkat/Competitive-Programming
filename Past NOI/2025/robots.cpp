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
signed main()
{
	int h,w;
	cin>>h>>w;
	vi s(w);
	for(auto &x:s)cin>>x;
	unordered_set<int>ss;for(auto &x:s)ss.insert(x);
	int q;cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		int ans=2;
		if(ss.count(a) or ss.count(b))ans=1;
		cout<<ans<<el;
	}
	
	return 0;
}
