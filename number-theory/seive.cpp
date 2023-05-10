// https://vjudge.net/problem/UVA-543
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long int
const int N=1e7+10;
vector<int>isPrime(N,1);
vector<int>lowestPrime(N);
vector<int>highestPrime(N);
vector<int>primes;
void seive(){
    isPrime[1]=0;
    isPrime[0]=0;
    for(int i=4;i<N;i+=2){
        isPrime[i]=0;//even
        lowestPrime[i]=2;
    }
    for(int i=3;i<N;i+=2){
        
        if(isPrime[i]==1){
            lowestPrime[i]=i;
            for(int j=i*i;j<N;j+=2*i){
                isPrime[j]=0;
                if(!lowestPrime[j]){
                    lowestPrime[j]=i;
                }
            }
        }
    }
    primes.push_back(2);
    for(int i=3;i<N;i+=2){
        if(isPrime[i]==1)primes.push_back(i);
    }
}
vector<int> primeFactorsCalc(int n){
    vector<int>primeFactors;
    while(n>1){
        int x=lowestPrime[n];
        n/=x;
        primeFactors.push_back(x);
    }
    return primeFactors;
}
vector<int> distinctPrimeFactorsCalc(int n){
    vector<int> primeFactors;
    while(n>1){
        int x=lowestPrime[n];
        primeFactors.push_back(x);
        while(n%x==0&&n>1){
            n/=x;
        }
    }
    return primeFactors;
}

signed main(){
    seive();
    cout<<"Enter a number n to compute first n prime numbers : ";
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cout<<primes[i]<<" ";
    }
    cout<<endl;
    //Prime factors and divisor are same
    cout<<"Enter another number n to compute prime factors of n. For Example Prime Factors of 12 are {2,2,3} as 2 X 2 X 3 = 12 . ";
    cout<<endl;
    cout<<" =======> ";
    cin>>n;
    auto primeFactors=primeFactorsCalc(n);
    cout<<"Total Prime Factors : "<<primeFactors.size()<<endl;
    for(int i=0;i<primeFactors.size();++i)cout<<primeFactors[i]<<" ";
    cout<<endl;
}