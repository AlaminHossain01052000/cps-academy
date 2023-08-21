// find snodd(n!) or if n!=x then snodd(x)=NOD(1)+NOD(b)+NOD(c)+NOD(x) sich that divisors of x are 1,b,c,x
// https://algo.codemarshal.org/contests/icpc-dhaka-18/problems/C
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e7+10;
#define M 10000007
vector<int>primes;
bitset<N>isPrime;//It is 32 times memory saving
void seive(int n){
    n+=100;
    isPrime[1]=false;
    isPrime[0]=false;
    isPrime[2]=1;
    for(int i=3;i<n;i+=2)isPrime[i]=1;//all evens are 0
    for(int i=3;i*i<n;i+=2){
        
        if(isPrime[i]){
           
            for(int j=i*i;j<n;j+=2*i){
                isPrime[j]=0;
            }
        }
    }
    primes.push_back(2);

    for(int i=3;i<N;i+=2)if(isPrime[i])primes.push_back(i);

}
// if pf(n!)=x^a*y^b ,x and y are primes
// then snodd(n!)=(1+2+3+...a+1)*(1+2+3+.....b+1)
int snodd(int n){
    int ans=1;
    for(auto p:primes){
        if(p>n)break;
        int count=0;
        int temp=n;
        while(temp>0){
            count+=(temp/p);
            temp/=p;
        }
        count++;
        int x=((count*(count+1))/2);
        x%=M;
        ans*=x;
        ans%=M;
    }
    return ans;
}
signed main(){
    seive(1e6);
    int n;
    while(cin>>n){
        if(n==0)break;
        cout<<snodd(n)<<endl;
    }
    
}
///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///



// #include<bits/stdc++.h>
// using namespace std;


// typedef long long ll;
// typedef vector<int> vi;
// typedef vector<ll> vl;
// typedef vector<vi> vvi;
// typedef vector<vl> vvl;
// typedef pair<int,int> pii;
// typedef pair<double, double> pdd;
// typedef pair<ll, ll> pll;
// typedef vector<pii> vii;
// typedef vector<pll> vll;
// typedef double dl;

// #define endl '\n'
// #define PB push_back
// #define F first
// #define S second
// #define all(a) (a).begin(),(a).end()
// #define rall(a) (a).rbegin(),(a).rend()
// #define sz(x) (int)x.size()

// const double PI = acos(-1);
// const double eps = 1e-9;
// const int inf = 2000000000;
// const ll infLL = 9000000000000000000;
// #define MOD 10000007

// #define mem(a,b) memset(a, b, sizeof(a) )
// #define sqr(a) ((a) * (a))

// #define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
// #define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
// //
// //debug
// template<typename F,typename S>ostream&operator<<(ostream&os,const pair<F,S>&p){return os<<"("<<p.first<<", "<<p.second<<")";}
// template<typename T>ostream&operator<<(ostream&os,const vector<T>&v){os<<"{";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"}";}
// template<typename T>ostream&operator<<(ostream&os,const set<T>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<",";os<<*it;}return os<<"]";}
// template<typename T>ostream&operator<<(ostream&os,const multiset<T>&v) {os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
// template<typename F,typename S>ostream&operator<<(ostream&os,const map<F,S>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<it->first<<" = "<<it->second;}return os<<"]";}
// #define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
// void faltu(){cerr << endl;}
// template<typename T>void faltu(T a[],int n){for(int i=0;i<n;++i)cerr<<a[i]<<' ';cerr<<endl;}
// template<typename T,typename...hello>void faltu(T arg,const hello&...rest){cerr<<arg<<' ';faltu(rest...);}
// //#else
// //#define dbg(args...)

// ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
// ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }


// int dx[] = { 0, 0, +1, -1, -1  +1, -1, +1 };
// int dy[] = { +1, -1, 0, 0, -1, +1, +1, -1 };


// const int MX = 1e7+123;
// bitset<MX> is_prime;
// vector<int> prime;

// void primeGen ( int n )
// {
//     n += 100;
//     for ( int i = 3; i <= n; i += 2 ) is_prime[i] = 1;

//     int sq = sqrt ( n );
//     for ( int i = 3; i <= sq; i += 2 ) {
//         if ( is_prime[i] == 1 ) {
//             for ( int j = i*i; j <= n; j += ( i + i ) ) {
//                 is_prime[j] = 0;
//             }
//         }
//     }

//     is_prime[2] = 1;
//     prime.push_back (2);

//     for ( int i = 3; i <= n; i += 2 ) {
//         if ( is_prime[i] == 1 ) prime.push_back ( i );
//     }
// }


// int main()
// {
// 	optimize();

// 	int lim = 1e6;
// 	primeGen(lim);

// 	int n;

// 	while ( cin >> n ) {
// 	    if ( n == 0 ) break;

// 	    ll ans = 1;
// 	    for ( auto p : prime ) {
// 	        if ( p > n ) break;

// 	        ll cnt = 0;

// 	        int tmp = n;
// 	        while ( tmp > 0 ) {
// 	            cnt += ( tmp / p );
// 	            tmp /= p;
// 	        }

// 	        cnt++;

// 	        ll sum = ( cnt * ( cnt + 1 ) ) / 2;
// 	        sum %= MOD;
// 	        ans *= sum;
// 	        ans %= MOD;

// 	    }


// 	    cout << ans << endl;

// 	}


// 	return 0;
// }