// https://www.spoj.com/problems/MAIN12B/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e7+100;
vector<int>primes;
vector<int>isPrime(N,true);
int lcm(int a,int b){
    return (a*(b/__gcd(a,b)));
}
void seive(){
    isPrime[1]=false;
    for(int i=3;i*i<N;i+=2){
        if(isPrime[i]){
            for(int j=i*i;j<N;j+=2*i){
                isPrime[j]=false;
            }
        }   
        
    }
    primes.push_back(2);
    for(int i=3;i<N;++i)if(isPrime[i])primes.push_back(i);
}
void primeFactorization(int n,set<int>&s){
 
    for(auto prime:primes){
        if(prime*prime>n)break;
        if(n%prime==0){
            s.insert(prime);
            while(n%prime==0){
                n/=prime;
            }
        }
    }
    if(n>1)s.insert(n);
    
}
signed main(){
    seive();
    int t;
    cin>>t;
    for(int tc=1;tc<=t;++tc){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;++i)cin>>v[i];
        set<int>s;
        for(int i=0;i<n;++i){
            primeFactorization(v[i],s);
        }
        cout<<"Case #"<<tc<<": "<<s.size()<<endl;
        for(auto &ele:s)cout<<ele<<endl;
    }
}