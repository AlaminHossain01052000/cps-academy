#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e7+100;
const int M=1e9+7;
bitset<N>isPrime;
vector<int>primes;
// map<int,int>lp;
void seive(int n){
    n+=100;
    int limit=sqrt(n)+10;
    isPrime[2]=1;
    for(int i=3;i<=limit;i+=2)isPrime[i]=1;
    for(int i = 3; i <= limit; i += 2) {
        if(isPrime[i]==1) {
            for(int j = i * i; j < n; j += i + i) {
                isPrime[j] = 0;
            }
        }
    }
    primes.push_back(2);
    for(int i=3;i<=n;i+=2){
        if(isPrime[i])primes.push_back(i);
    }
}
//theory : sod(12)=(2^0+2^1+2^2)*(3^0+3^1);
// primeFactorization(12)=(2^2)*(3^1)=(4*3)
int sod(int n){
    int sumOfDivisors=1;

    for(auto &primeNumber:primes){
        if(primeNumber*primeNumber>n)break;
        if(n%primeNumber==0){
            int currentSum=1; //primeNumber^0
            int powerOfP=1; //primeNumber^0
            while(n%primeNumber==0){
               powerOfP*=primeNumber;//2=(2*2)
               currentSum+=powerOfP;//currentSum=(1+2^1+2^2+....) where 1=2^0
               n/=primeNumber;
            }
            sumOfDivisors*=currentSum;
        }
    }
    if(n>1)sumOfDivisors*=(1+n);//if n=5 then 5^0+5^1, assume n was 20 at first

    return sumOfDivisors;
}
//using formula of a linear sequnece p^0+p^1+p^2+...p^n
//theory : primeFactorization(n)=(p^x)*(q^y)
// sod(n)=(p^0+p^1+...p^x)(q^0+q^1+.....q^y)=((p^(x+1))-1)/p-1)*((q^(y+1))-1)/q-1)
int sod2(int n){
    int sumOfDivisors=1;

    for(auto primeNumber:primes){
        if(primeNumber*primeNumber>n)break;
        if(n%primeNumber==0){
            int powerOfP=primeNumber; //primeNumber
            while(n%primeNumber==0){
               powerOfP*=primeNumber;//2=(2*2)
               n/=primeNumber;
            }
            sumOfDivisors*=((powerOfP-1)/(primeNumber-1));
        }
    }
    if(n>1)sumOfDivisors*=(1+n);//if n=5 then 5^0+5^1, assume n was 20 at first

    return sumOfDivisors;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    seive(1e6);
    int t=1;
    // cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;++i){
            ans+=sod(i);
            ans%=M;
        }
        cout<<ans<<endl;
    }
    
}
// 10
// 1
// =>1
// 2
// =>3
// 5
// =>6
// 10
// =>18
// 15
// =>24
// 20
// =>42
// 30
// =>72
// 60
// =>168
// 100
// =>217
// 1010
// =>1836