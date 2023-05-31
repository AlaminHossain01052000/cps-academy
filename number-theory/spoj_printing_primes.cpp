// https://www.spoj.com/problems/TDPRIMES/
#include<bits/stdc++.h>
using namespace std;
// #define int long long int
// const int N=1e8+10;
// vector<int>primes;
// bitset<N>isPrime;
// void seive(){
//     isPrime[1]=false;
//     isPrime[0]=false;
//     primes.push_back(2);
//     for(int i=3;i<N;i+=2)isPrime[i]=1;
//     for(int i=3;i*i<N;i+=2){
        
//         if(isPrime[i]){
           
//             for(int j=i*i;j<N;j+=2*i){
//                 isPrime[j]=0;
//             }
//         }
//     }

//     for(int i=3;i<N;i+=2)if(isPrime[i])primes.push_back(i);

// }
const int MX = 5e7+123;//It will decrease the memory limit by 2. If N=1e8 then take MX=1e8/2
bool seive[MX];
vector<int> primes;
 
void bitwiseSeive(int limit) {
    limit += 100;
    int sqrtn = sqrt(limit);
    for(int i = 3; i <= sqrtn; i += 2) {
        if(!seive[i>>1]) {
            for(int j = i * i; j < limit; j += i + i) {
                seive[j>>1] = 1;
            }
        }
    }
    
    primes.push_back(2);
    for(int i = 3; i < limit; i += 2) {
        if(!seive[i>>1]) primes.push_back(i);
    }
}
signed main(){
    bitwiseSeive(1e8);
    // cout<<primes.size()<<endl;
    // return 0;
    int i=0;
    while (i<primes.size()&&primes[i]<1e8)
    {
        cout<<primes[i]<<endl; 
        i+=100;
        /* code */
    }
    
}
// #define int long long int
// const int N=1e8+10;
// vector<int>primes;
// bitset<N>isPrime;
// void bitsetSeive(){
//     isPrime[1]=false;
//     isPrime[0]=false;
//     primes.push_back(2);
//     for(int i=3;i<N;i+=2)isPrime[i]=1;
//     for(int i=3;i*i<N;i+=2){
        
//         if(isPrime[i]){
           
//             for(int j=i*i;j<N;j+=2*i){
//                 isPrime[j]=0;
//             }
//         }
//     }
 
//     for(int i=3;i<N;i+=2)if(isPrime[i])primes.push_back(i);
 
// }