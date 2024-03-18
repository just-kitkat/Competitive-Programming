// Author: JustKitkat
// Status: WIP

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >,
rb_tree_tag, tree_order_statistics_node_update> ordered_map;
#define el "\n"
#define arr array
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vii vector<pair<int,int>>
#define vllll vector<pair<ll,ll>>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(a) (a).begin(), (a).end()
#define FOR(a,b) for(auto i=a;i<b;++i)
#define DFOR(a,b) for(auto i=a;i>=b;--i)
#define JFOR(a,b) for(auto j=a;j<b;++j)
#define DJFOR(a,b) for(auto j=a;j>=b;--j)

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

#define __time__ { auto duration = chrono::duration<double>( /* Show runtime */ \
chrono::high_resolution_clock::now() - BEG); cout<<"Time: "<<duration.count()<<endl;}
#define __output__ { FILE* file = freopen("../../../Testcases/test.out", "w", stdout); }
#define __input__ { FILE* file = freopen("../../../Testcases/test.in", "r", stdin); }

const int MAX_N = 1e5 + 5;
const ll INF = 1e9;
const double PI = acos(-1);
const auto BEG = std::chrono::high_resolution_clock::now(); //Begining of the program


int main() {
    ordered_map om;
 
    om.insert({ 23, 20 });
    om.insert({ 23, 10 });
    om.insert({ 23, 30 });
    om.insert({ 12, 35 });
    om.insert({ 12, 22 });
 
    // Another method to insert pair
    // om.insert(make_pair(23, 20));
 
    // Print the contents of the map
    cout << "Contents of map:\n";
    cout << "KEY\tELEMENT\n";
    for (auto x:om) {
        cout << x.F << "\t" << x.S << "\n";
    }
 
    // value at 3rd index in sorted array.
    cout << "The value at 3rd index is "
         << "{" << om.find_by_order(3)->first << ", "
         << om.find_by_order(3)->second << "}\n";
 
    // Index of pair {23, 30}
    cout << "The index of pair {23, 30} is "
         << om.order_of_key({ 23, 30 }) << endl;
 
    // Pair {23, 40} is not in the map but it will show the
    // index number if it was there in sorted array
    cout << "The index of pair {23, 40} is "
         << om.order_of_key({ 23, 40 }) << endl;
 
    return 0;
}
// Note: int64_t for exactly 64 bit signed int