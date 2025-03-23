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
#define all(x) (x).begin(), (x).end()
#define show(x) cout<<#x<<": "<<x<<el;

signed main()
{
	int n,k;
	cin>>n>>k;
	vii a(n);
	for(auto &x:a)cin>>x.F>>x.S;
	vi e(k);
	for(auto &x:e)cin>>x;
	e.push_back((int)-1e9-5);
	sort(e.begin(),e.end());
	sort(all(a));
	int ans=0;
	unordered_map<int,vi>possible;
	for(auto &x:a){
		int left=*--upper_bound(all(e),x.F)-x.F;
		int right=*lower_bound(all(e),x.F)-x.F;
		left=abs(left),right=abs(right);
		int lo=min({x.S,left,right});
		if(lo!=x.S){
			if(left<right)possible[x.F-left].pb(x.F);
			else if(right<left)possible[x.F+right].pb(x.F);
			else{
				if(!possible.count(x.F-left))possible[x.F+right].pb(x.F);
				else possible[x.F-left].pb(x.F);
			}
		}
		ans+=min({x.S,left,right});
		//show(x.F);
		//show(left);show(right);show(ans);
	}
	for(auto &x:possible)ans++;
	cout<<ans;
	return 0;
}
/*
2 2
1 2
4 10
2 6
*/
