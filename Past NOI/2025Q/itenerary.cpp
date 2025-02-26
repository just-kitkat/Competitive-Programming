#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define FOR(a,b) for(int i=a;i<b;++i)
#define ii pair<int,int>
#define el '\n'
#define show(x) cout<<#x<<": "<<x<<endl;

vi s;
unordered_map<int,vi>adj;
unordered_map<int,unordered_set<int>>store;
int dfs(int v, int u, int ind){
    return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    int allOnes=1;
    int line=1;
    FOR(0,n-1){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        store[u].insert(v);
        store[v].insert(u);
        if(u!=1)allOnes=0;
        if(u!=i+1 or v!=i+2)line=0;
    }
    s.resize(m);
    for(auto &x:s)cin>>x;
    unordered_map<int,int>cnt;
    for(auto &x:s)cnt[x]++;
    if(line){
        for(int j=1;j<n+1;++j){
            // show(j);
            // left or right
            int ind=0,num=j;
            if(s[0]==num)ind++;
            if(s[0]==num and m==1){
                cout<<1<<el;
            }else if(s[0]==num and s[1]==num and m==2){
                cout<<1<<el;
            }
            else{
                if(s[ind]>num or (ind+1<m and s[ind]==num and s[ind+1]<num)){
                    // go right
                    FOR(num+1,n+1){ if(ind<m and s[ind]==i) ind++;}// show(s[ind]);show(i);}
                    // then go left
                    for(int i=n;i>0;--i) {if(ind<m and s[ind]==i) ind++;}//show(s[ind]);show(i);}
                    // go back to original pos
                    FOR(1,j+1) {if(ind<m and s[ind]==i) ind++;}//show(s[ind]);show(i);}
                }else{
                    // show("ee");
                    // go left
                    for(int i=num-1;i>0;--i) {if(ind<m and s[ind]==i) ind++;}//show(s[ind]);show(i);}
                    // go right
                    FOR(2,n+1) if(ind<m and s[ind]==i) ind++;
                    // go back to original pos
                    for(int i=n;i>=j;--i) if(ind<m and s[ind]==i) ind++;
                }
                // show(ind);
                if(ind==m)cout<<1<<el;
                else cout<<0<<el;
            }
        }
    }
    else{
        assert(0);
    }
    return; // ugh
    if(m==2*n-1){
        FOR(1,n+1){
            int x=dfs(i,-1,0);
            if(x==false)cout<<0<<el; else cout<<1<<el;
        }
    }
    else if(allOnes){ // subtask 2
        vi morethan1;
        for(auto &x:cnt)if(x.second>1)morethan1.push_back(x.first);
        sort(morethan1.begin(),morethan1.end());
        if(morethan1.size()>2 or (morethan1[0]!=1 and n>2) or cnt[morethan1[1]]>2){
            // output 0 for all
            FOR(0,n)cout<<0<<el;
        }else if(morethan1.size()==2){
            // there are 2 ones, morethan1[0]==1
            if(s[0]==s.back() and cnt[s[0]]==2)FOR(1,n+1)cout<<(i==s[0]?1:0)<<el;
        }else if(morethan1.size()==1){
            FOR(1,n+1)cout<<(i==morethan1[0]?1:0)<<el;
        }else{ // morethan1.size()==0
            assert(0); // it shouldnt reach here
        }

    }

}

/*

5 5
1 2
2 3
3 4
4 5
2 3 2 1 2


DFS will visit all roads twice
find if there exist some dfs that contains s[1..m] in that order
query subtree?
it is possible if consecutive nodes are in the same subtree

find if there exist a number in a subtree

st 1: dfs each node, dfs the s[i] first, can use vis array
st 2: always possible
st 3, 4: line. always possible as long as it is possible from the first node
st 5: setmerge to find elements in a certain subtree

when you dfs you have to take either the left or right from s


*/

