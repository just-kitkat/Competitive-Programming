#include <bits/stdc++.h>
using namespace std;
int numTilings(int n) {
    vector<long long> dp={1,2,5};
    n--;
    if(n<3)return dp[n];
    for(int i=3;i<=n;i++)dp.push_back(fmod((dp[i-1]*2+dp[i-3]),(pow(10,9)+7LL)));
    return dp[n];
}
int main(){
	int n;
    cin>>n;
    cout<<numTilings(n);
}