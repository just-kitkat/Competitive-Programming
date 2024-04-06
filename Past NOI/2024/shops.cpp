/*
 * t1.cxx (AC)
 * 
 * Copyright 2024 Unknown <ioi2010@soctf-pl-nitro>
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
#define el "\n"
#define ll long long
#define vi vector<int>
#define vii vector<pair<int,int>>
#define vll vector<ll>
#define pb push_back
#define FOR(a,b) for(auto i=a;i<b;++i)
#define JFOR(a,b) for(auto j=a;j<b;++j)
#define F first
#define S second


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
    vector<vi> ed(m, vi(3));
	vector<char> ans(n,'A');
    int rr=0;
    FOR(0,m){
        int a,b,w;
        cin>>a>>b>>w;
        ed.pb({w,a,b});
    }

    sort(ed.begin(), ed.end());
	for(auto x:ed){
        int w=x[0],a=x[1],b=x[2];
        a--;b--;
        if(ans[a]=='A'||ans[b]=='A')rr=w;
		if(ans[a]=='A'&&ans[b]=='A'){
			ans[a]='B';
			ans[b]='D';
		}else if(ans[a]!='A'&&ans[b]!='A')continue;
		else{
			if(ans[a]!='A')ans[b]=(ans[a]=='B'?'D':'B');
			else ans[a]=(ans[b]=='B'?'D':'B');
		}
	}
	
	cout<<rr<<el;
	for(auto x:ans)cout<<x;
	cout<<el;
	return 0;
}

/*
5 6
3 2 1
4 2 1
5 3 1
1 3 1
1 4 1
2 3 1

7 6
1 2 1
2 3 1
3 4 1
4 5 1
5 6 1
6 7 1
*/
