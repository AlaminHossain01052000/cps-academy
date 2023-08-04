// https://www.spoj.com/problems/DIVSUM2/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e8+100;
vector<int> isPrime(N,1);
vector<int>primes;
// map<int,int>lp;
void seive(int n){
    n+=100;
    int limit=sqrt(n);
    isPrime[2]=1;
    
    for(int i = 3; i < limit; i += 2) {
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
int sod(int n){
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
    seive(1e8);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<sod(n)-n<<endl;
       
    }
}