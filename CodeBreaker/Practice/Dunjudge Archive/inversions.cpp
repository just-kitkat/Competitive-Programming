// Author: JustKitkat
// Status: WIP

#include <bits/stdc++.h>

using namespace std;

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
#define show(x) cerr << #x << " is " << x << endl;
#define show2(x,y) cerr << #x << " is " << x << " " << #y << " is " << y << endl;
#define show3(x,y,z) cerr << #x << " is " << x << " " << #y << " is " << y << " " << #z << " is " << z << endl;
#define discretize(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());

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
int ans;

void merge(int* arr1,int n1,int* arr2,int n2,int* input,int size){
    int i = 0, j = 0, k = 0;
    while(i<n1 && j<n2){
        if(arr1[i] <= arr2[j]) input[k++] = arr1[i++];
        else {input[k++] = arr2[j++];ans+=n1-i;}
    }
    while(i < n1) {input[k++] = arr1[i++];}
    while(j < n2) {input[k++] = arr2[j++];}
}


void mergeSort(int input[], int size){
    if(size == 1 || size == 0) return;
    int n1 = size/2, n2 = size - n1;
    int* arr1 = new int[n1];
    int* arr2 = new int[n2];
    for(int i=0;i<n1;i++) arr1[i] = input[i];
    int k=0;
    for(int j=n1;j<size;j++) arr2[k++] = input[j];
    
    mergeSort(arr1,n1);
    mergeSort(arr2,n2);
    merge(arr1,n1,arr2,n2,input,size);
 }

void solve(int tc){
    int n;
    cin>>n;
    int a[n];
    FOR(0,n)cin>>a[i];
    ans=0;
    mergeSort(a,n);
    cout<<ans<<el;

    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //__output__ // Redirect output to test.out
    //__input__ // Read test.in for input

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }

    //__time__ //Runtime
}
// Note: int64_t for exactly 64 bit signed int