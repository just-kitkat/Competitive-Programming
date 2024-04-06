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

int tb(int number)
{
	int dv;
	while(number!=0){
		dv=number%10;
		if(dv>1)
			return 0;
		number=number/10;
	}
	return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //__output__ // Redirect output to test.out
    //__input__ // Read test.in for input

    vector<bool> s((int)(1e5+10),false);
    s[0]=1;
    s[1]=1;
    // vi a={10,11,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111};
    // vi aa;
    vector<int>b={
        0,1,
        10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111,10000,
        10001,10010,10011,10100,10101,10110,10111,11000,11001,11010,11011,
        11100,11101,11110,11111,100000,

        10*10,
        10*11,
        11*11,
        10*10*10,10*10*11,10*11*11,11*11*11,
        10*10*10*11,10*10*11*11,10*11*11*11,11*11*11*11,
        101*11,101*11*11,
        110*11,110*11*11,110*101,111*111,110*110,101*101,100*100,
        111*11,111*11*11,111*101,111*111,111*110,
        1001*11,
        1010*11,
        1011*11,1100*11,1101*11,1110*11,1111*11,10201

    };
    // vi a={10,11};
    // int p1=0,p2=0;
    // while(p2<16){//a.back()<1e6+1){
    //     // FOR(0,a.size()){
    //     //     JFOR(i,a.size()){
    //     //         a.pb(a[i]*a[j]);
    //     //     }
    //     // }
    //     // for(auto x:a)cout<<x<<' ';cout<<endl;
    //     int xx=a[p1]*a[p2];
    //     if(xx>1e5+1)continue;
    //     a.pb(xx);
    //     if(tb(xx))a.pb(xx+1);
    //     if(p1==p2){
    //         p2+=1;
    //         p1=0;
    //     }else{
    //         p1++;
    //     }
        
    // }
    for(auto x:b){if(x<((int)(1e5+10)))s[x]=1;}
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        // int n;
        // cin>>n;
        // vi a={1,10*10*11,11*11*10,11*121, 10*1111,111*11,
        // 12210,};
        string nn;
        cin>>nn;
        int c=0;
        DFOR(nn.size()-1,0){
            if(nn[i]!='0')break;
            c++;
        }
        int n=stoi(nn);
        n/=pow(10,c);
        if(s[n])cout<<"YES\n";
        else cout<<"NO\n";
        // sort(all(a));
        // for(auto x:a)cout<<x<<' ';cout<<endl;

    }

    //__time__ //Runtime
}
// Note: int64_t for exactly 64 bit signed int