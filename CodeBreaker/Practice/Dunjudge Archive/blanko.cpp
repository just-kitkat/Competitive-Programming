// Author: JustKitkat
// Status: WIP

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define int long long
//#define ll long long
#define el "\n"
#define arr array
#define ld long double
#define ii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vii vector<ii>
#define vllll vector<pll>
#define umap unordered_map
#define uset unordered_set
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(a) (a).begin(), (a).end()
#define FOR(a,b) for(auto i=a;i<b;++i)
#define DFOR(a,b) for(auto i=a;i>=b;--i)
#define JFOR(a,b) for(auto j=a;j<b;++j)
#define DJFOR(a,b) for(auto j=a;j>=b;--j)
#define show(x) cerr<<#x<<" is "<<x<<endl;
int n=0, m=0, k=0, q=0;
typedef long long ll;
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n,k; cin>>n>>k;
    string s; cin>>s;
    vi ans;
    set<ii>ss;
    int cnt[10]={0};
    int l=0, op=0;
    // vii store;
    vi store;
    if(n-k==1){
		int ans=9;
		for(auto &x:s)ans=min((ll)x-'0',ans);
		cout<<ans;
		return 0;
	}
    while(k!=n){
        int total=0, low=0;
        FOR(0,10)total+=cnt[i];
		FOR(l+total,k+1) cnt[s[i]-'0']++;
        FOR(0,10)if(cnt[i]!=0){
            low=i;
            break;
        }
		while(op==0 and low==0){
            store.push_back(low);
            cnt[low]--;
            low=0;
            FOR(0,10)if(cnt[i]!=0){low=i;break;}
		}
		if(op==0){
			for(auto &x:store) cnt[x]++;
			store.clear();
			op = 1;
		}
		ans.push_back(low);
        int ind=l;
        while(s[ind]-'0'!=low)ind++;
		FOR(l,ind+1) cnt[s[i]-'0']--;
		l=ind+1, k++;
	}
    
    
	for(auto &x:ans)cout<<x;
}







