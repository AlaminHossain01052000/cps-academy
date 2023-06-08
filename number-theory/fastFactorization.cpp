#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e7+10;
vector<int> isPrime(N,1);
vector<int>primes;
vector<int>primeFactors[N];
void seive(){
    
    int limit=sqrt(N);
 
    
    for(int i = 3; i < limit; i += 2) {
        
        if(isPrime[i]==1) {
 
            for(int j = i * i; j < N; j += 2*i) {
                isPrime[j] = 0;
                
            }
        }
    }
    primes.push_back(2);
    for(int i=3;i<N;i+=2)if(isPrime[i])primes.push_back(i);
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    seive();
    //getting disting prime factors using harmonic mean
    for(auto p:primes){
        for(int i=p;i<1e7;i+=p)primeFactors[i].push_back(p);
    }
    for(int i=1;i<=10;++i){
        cout<<i<<" : ";
        for(auto &ele:primeFactors[i])cout<<ele<<" ";
        cout<<endl;
    }
}