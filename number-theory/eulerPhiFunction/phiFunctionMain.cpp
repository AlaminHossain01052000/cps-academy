// https://forthright48.com/euler-totient-or-phi-function/

#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e6+110;
vector<int>primes;
bitset<N>isPrime;//It is 32 times memory saving
void seive(int n){
    n+=100;
    isPrime[1]=false;
    isPrime[0]=false;
    
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
// The objective of euler phi function is finding number of co-primes of a number n between 1 to n
// Suppost phi(8)=4 and these ase 1,3,5,7
// Formula: phi(n)=n*{(p1-1/p1)*((p2-1)/p2)*((p3-1)/p3)} if primeFactorization of n=p1^a1*p2^a2*p3^a3
// Time complexity==complexity of prime factorization= O(sqrt(n)/ln(sqrt(n)))
int phi(int n){
    int ans=n;
    for(auto &p:primes){
        if(p*1LL*p>n||n==0)break;
        if(n%p==0){
            ans/=p;
            ans*=(p-1);
            while(n%p==0)n/=p;
        }
    }
    if(n>1){
        ans/=n;
        ans*=(n-1);

    }
    return ans;
}
signed main(){
seive(1e6);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<phi(n)<<endl;
    }
}
// Input:
// 5
// 1
// 2
// 3
// 4
// 5

// Output:
// 1
// 1
// 2
// 2
// 4