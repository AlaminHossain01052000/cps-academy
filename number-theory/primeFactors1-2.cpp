#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e8+10;
vector<int> isPrime(N,1);
vector<int>primes;
int lp[N];
void seive(){
    
    int limit=sqrt(N);
    isPrime[2]=1;
    
    for(int i = 3; i < limit; i += 2) {
        
        if(isPrime[i]==1) {
            lp[i]=i;
            for(int j = i * i; j < N; j += 2*i) {
                isPrime[j] = 0;
                if(!lp[j])lp[j]=i;
            }
        }
    }
    
}
vector<int> primeFactorization(int n){
    
    vector<int>primeFactors;
    
    while(n>1){
        int lowestPrime;
        if(n%2==0)lowestPrime=2;
        else if(isPrime[n])lowestPrime=n;
        else lowestPrime=lp[n];
        while(n%lowestPrime==0){
            primeFactors.push_back(lowestPrime);
            n/=lowestPrime;
        }
    }

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
     seive();
    while(x!=0){
        
        if(x==1||x==-1){
            cout<<x<<endl;
            continue;
        }
       
        auto primeFactors=primeFactorization(x);
        cout<<primeFactors.size()<<endl;
        // cin>>x;
        // return 0;
        
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