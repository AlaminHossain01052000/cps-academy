// https://codeforces.com/contest/776/problem/B

#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=100100;
bitset<N>isPrime;

void bitsetSeive(int n){
    n+=100;
    isPrime[2]=1;
    for(int i=3;i<n;i+=2)isPrime[i]=1;
    for(int i=3;i*i<n;i+=2){
        
        if(isPrime[i]){
           
            for(int j=i*i;j<n;j+=2*i){
                isPrime[j]=0;
            }
        }
    }
 

 
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // cout<<primes.size()<<endl;
    // return 0;
    int n;
    cin>>n;
    bitsetSeive(n);
    if(n>2)cout<<2<<endl;
    else cout<<1<<endl;
    for(int i=2;i<=n+1;++i)isPrime[i]?cout<<1<<" ":cout<<2<<" ";
    cout<<endl;
    
}

