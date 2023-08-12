// If we need to calculate phi of numbers from a range [a,b] such that for [1,6] the phi(1)=0,phi(2)=1,phi(3)=2,phi(4=2,phi(5)=4,phi(6)=2 then phi using harmonic min is useful

#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e6+110;
vector<int> phi(N);
// The objective of euler phi function is finding number of co-primes of a number n between 1 to n
// Suppost phi(8)=4 and these ase 1,3,5,7
// Formula: phi(n)=n*{(p1-1/p1)*((p2-1)/p2)*((p3-1)/p3)} if primeFactorization of n=p1^a1*p2^a2*p3^a3
// Time complexity==complexity of prime factorization= O(nln(n))
void phiHarmonicMean(int n){
    n+=100;
    for(int i=1;i<=n;++i){
        phi[i]=i;
    }
    for(int i=2;i<=n;++i){
        if(phi[i]==i){
            for(int j=i;j<=n;j+=i){
                phi[j]*=(i-1);
                phi[j]/=i;
            }
        }
    }
}
signed main(){
    phiHarmonicMean(1e6);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<phi[n]<<endl;
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