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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	unordered_map<int,ii>change;
	int n,m;
	cin>>n>>m;
	vector<vi> a(n,vi(3));
	for(auto &x:a){
		cin>>x[0]>>x[1];
	}
	vi t(m);
	FOR(0,m){
		int x;cin>>x;
		x--;
		a[x][2]++;
	}
	// [i][idx]
	// idx=0 top left  =1 top  =2 top right
	// idx=3 right     =4 bottom right
	// idx=5 bottom    =6 bottom left
	// idx=7 left
	
	int cnt=0;
	auto b=a;
	sort(all(a));
	FOR(0,n){
		change[a[i][1]].S+=2*cnt;
		cnt+=a[i][2];
	}
	cnt=0;
	for(int i=n-1;i>=0;--i){
		change[a[i][1]].S-=2*cnt;
		cnt+=a[i][2];
	}
	
	//FOR(0,n)a[i][0]+=change[a[i][2]].F, a[i][1]+=change[a[i][2]].S;
	//sort(all(a),cmp);
	//for(auto &x:b)cout<<x[0]+change[{a[<<' '<<x[1]<<el;
	FOR(0,n){
		cout<<b[i][0]+change[b[i][1]].F<<' '<<b[i][1]+change[b[i][1]].S<<el;;
	}
	
	return 0;
}

// go through each rabbit and calculate its final position
/*
 * for each rabbit:
 *   find how many steps in each direction it has to take
 *   based on the thumps 
 * 
3 1
1 10
1 20
1 30
3
*/
