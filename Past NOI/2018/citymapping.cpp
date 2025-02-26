#include "citymapping.h"
#include <bits/stdc++.h>
using namespace std;
// #define ll long long

mt19937_64 rnd(3141);
#define ll long long
#define show(x) cout<<#x<<": "<<x<<endl;
#define show_vec(v) {for(auto &x:v)cout<<x<<' ';cout<<endl;}
#define show_vecp(v) {for(auto &x:v)cout<<x.first<<','<<x.second<<" | ";cout<<endl;}
int rng(int x, int y){return rnd()%(y-x+1)+x;}
vector<int>gA,gB,gW;
void discover(int root, vector<int>&subtree){
    // base case: subtree empty
    if(subtree.size()<=1) return;

    // get random root
    root=subtree[rng(1,subtree.size())-1];
    subtree.erase(find(subtree.begin(),subtree.end(),root));

    // show(root);
    // show_vec(subtree);

    // get distances to all nodes
    vector<pair<ll,int>>dist;
    for(auto &x:subtree)dist.push_back({get_distance(root,x),x});

    // get shortest node -- child (this node is adj to root)
    sort(dist.begin(),dist.end());
    int child = dist[0].second;
    gA.push_back(child), gB.push_back(root), gW.push_back(dist[0].first);

    // get all distances from child
    vector<pair<ll,int>>dist2;
    unordered_map<int,ll>distFromChild;
    for(auto &x:subtree)
        if(x!=child)
            dist2.push_back({get_distance(child,x),x}),
            distFromChild[x]=dist2.back().first;

    // determine subtree1
    vector<int> subtree1;
    vector<pair<ll,int>>others;
    for(auto &x:dist){
        if(x.second!=child){
            if(x.first > distFromChild[x.second]) subtree1.push_back(x.second);
            else others.push_back(x);
        }
    }
    subtree1.push_back(child);
    discover(1, subtree1);

    // determine subtree2 (all in subtree n subtree1') ( n rep set intersection )
    if(others.size()){
        int child2=others[0].second;
        gA.push_back(child2), gB.push_back(root), gW.push_back(others[0].first);
        if(others.size()==1)return;
        // get all distances
        unordered_map<int,ll>distFromChild2;
        vector<int> subtree2;
        vector<pair<ll,int>>subtree3;
        for(auto &x:others)
            if(x.second!=child2)distFromChild2[x.second]=get_distance(child2,x.second);
        for(auto &x:dist){
            if(distFromChild2.count(x.second)){
                if(x.first>distFromChild2[x.second])subtree2.push_back(x.second);
                else subtree3.push_back(x);
            }
        }
        subtree2.push_back(child2);
        if(subtree3.size()){
            sort(subtree3.begin(),subtree3.end());
            int child3=subtree3[0].second;
            gA.push_back(child3), gB.push_back(root), gW.push_back(subtree3[0].first);
        }
        vector<int> realsubtree3;
        for(auto &x:subtree3)realsubtree3.push_back(x.second);
        discover(1, subtree2);
        discover(1, realsubtree3);
    }

}

void find_roads(int N, int Q, int A[], int B[], int W[]){
    gA.clear(),gB.clear(),gW.clear();
    vector<int>r;
    int root=1;
    vector<int>subtree;
    for(int i=1;i<=N;++i)r.push_back(i);
    int randomNode=rng(1,N);
    discover(randomNode, r);
    for(int i=0;i<N-1;++i)A[i]=gA[i],B[i]=gB[i],W[i]=gW[i];
    // for(int i=0;i<N-1;++i)cout<<A[i]<<' ';cout<<endl;
}

/*

1---2---3---4---5
  8   2   3   3

Query all distances from 3:
node: dist
1: 10
2: 2
4: 3
5: 6

*/
