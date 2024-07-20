#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
namespace __gnu_pbds{
          typedef tree<long long,
                       null_type,
                       less_equal<long long>,
                       rb_tree_tag,
                       tree_order_statistics_node_update> ordered_set;
}
using namespace __gnu_pbds;

// use less<ll> for ordered_set instead of ordered_multiset
// use greater<ll> and greater_equal<ll> for reversed sets.

#define endl '\n'
#define ll long long
#define LSB __builtin_ctzll
#define MSB 63-__builtin_clzll
#define BITS __builtin_popcountll
#define s(i) (*s.find_by_order(i)) // Warning : Read this line.
#define mem(a,v) memset(a,v,sizeof(a))

const int MOD=1e9+7;
const int MAX=1e5+55;
const int INF=1e9+77;
const ll INFINF=1e18+1e17;
const double PI=acos(-1.0);


ll Power(ll x,ll y){
         if(!y) return 1;
         ll s=Power(x,y>>1);
         s*=s;
         if(y&1) s*=x;
         return s;
}







void Insert(ordered_set &s,ll x){

     s.insert(x);

}


bool Exist(ordered_set &s,ll x){

     if((s.upper_bound(x))==s.end()){
        return 0;
     }
     return ((*s.upper_bound(x))==x);

}


void Erase(ordered_set &s,ll x){

     if(Exist(s,x)){
        s.erase(s.upper_bound(x));
     }

}


int Idx(ordered_set &s,ll x){

    if(!Exist(s,x)){
        return -1;
    }
    return (s.order_of_key(x));

}


int LastIdx(ordered_set &s,ll x){

    if(!Exist(s,x)){
        return -1;
    }
    if(s((int)s.size()-1)==x){
        return (int)(s.size())-1;
    }
    return Idx(s,*s.lower_bound(x))-1;

}


ll Value(ordered_set &s,ll index){

   return (*s.find_by_order(index));

}


int Count(ordered_set &s,ll x){

     if(!Exist(s,x)){
        return 0;
     }
     return LastIdx(s,x)-Idx(s,x)+1;

}


void Clear(ordered_set &s){

     s.clear();

}


int Size(ordered_set &s){

     return (int)(s.size());

}



int main(){
//freopen("input.txt" , "r" , stdin);
//freopen("output.txt" , "w" , stdout);
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


     int n;
     cin>>n;
     vector<pair<pair<int,int>,int>> v(n);
     ordered_set s;
     for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        v[i]={{l,r},i};
        Insert(s,r);
     }

     sort(v.begin(),v.end());
     vector<int> ans(n);
     for(int i=0;i<n;i++){
        int l,r,id;
        tie(l,r)=v[i].first;
        id=v[i].second;
        ans[id]=LastIdx(s,r);
        Erase(s,r);
     }

     for(int i=0;i<n;i++){
        cout<<ans[i]<<endl;
     }



     return 0;

}