#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=3*1e3+123;
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
bool isAlmostPrime(int n){
    if(n<0)n*=-1;
    vector<int>primeFactors;

    for(auto primeNumber:primes){
        if(primeNumber*primeNumber>n)break;
        if(n%primeNumber==0){
            primeFactors.push_back(primeNumber);
            while(n%primeNumber==0){
                
                n/=primeNumber;
            }
        }
    }
    if(n>1)primeFactors.push_back(n);
    return primeFactors.size()==2;
    // return primeFactors;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    seive(3000);

    vector<int>almostPrimes(3010,false);
    for(int i=1;i<=3010;++i){
        if(isAlmostPrime(i)){
            almostPrimes[i]=true;
        }
    }




    int x;
    cin>>x;

    int ans=0;
    for(int i=1;i<=x;++i){
        if(almostPrimes[i]){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
    
    
}