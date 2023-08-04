#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=2e5+5;
vector<int> isPrime(N,1);
vector<int>primes;
// map<int,int>lp;
void seive(int n){
    n+=100;
    int limit=sqrt(n);
    isPrime[2]=1;
    
    for(int i = 3; i < limit; i += 2) {
        if(isPrime[i]==1) {
            for(int j = i * i; j < N; j += i + i) {
                isPrime[j] = 0;
            }
        }
    }
    primes.push_back(2);
    for(int i=3;i<=n;i+=2){
        if(isPrime[i])primes.push_back(i);
    }
}
vector<int> primeFactorization(int n){
    if(n<0)n*=-1;
    vector<int>primeFactors;

    for(auto primeNumber:primes){
        if(primeNumber*primeNumber>n)break;
        if(n%primeNumber==0){
            //primeFactors.push_back(primeNumber); //for distinct prime factors
            while(n%primeNumber==0){
                primeFactors.push_back(primeNumber);//for non-distict prime factors
                n/=primeNumber;
            }
        }
    }
    if(n>1)primeFactors.push_back(n);

    return primeFactors;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // seiveGen();
    int x;
    cin>>x;
    // int t=1;
     seive(1e5);
    while(x!=0){
        
        if(x==1||x==-1){
            cout<<x<<endl;
            continue;
        }
       
        auto primeFactors=primeFactorization(x);
        // cout<<primeFactors.size()<<endl;
        
        if(x<0){
            cout<<x<<" = "<<-1<<" x ";
            for(int i=0;i<primeFactors.size()-1;++i){
                cout<<primeFactors[i]<<" x ";
            }
            cout<<primeFactors[primeFactors.size()-1]<<endl;
            
        }
        else{
           cout<<x<<" = ";
            for(int i=0;i<primeFactors.size()-1;++i){
                cout<<primeFactors[i]<<" x ";
            }
            cout<<primeFactors[primeFactors.size()-1]<<endl;
        }

        cin>>x;
    }
}