// https://www.hackerearth.com/problem/algorithm/number-of-divisors-5/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e6 + 100;
bitset<N> isPrime;
vector<int> primeNumbers;

void seive(int n)
{
    n+=100;//safe zone
    isPrime[2]=1;
    for ( int i = 3; i <= n; i += 2 ) isPrime[i] = 1;
    for(int i=3;i*i<n;i+=2){
        if(isPrime[i]==1){
            for(int j=i*i;j<n;j+=2*i){
                isPrime[j]=0;
                
            }
        }
    }
    // computing all primes from 1 to n
    primeNumbers.push_back(2);
    //I can get the prime numbers in sqrt(n) as n has no divisor greater then sqrt(n)
    for(int i=3;i<=n;i+=2){
        if(isPrime[i]==1)primeNumbers.push_back(i);
    }
}
int NOD(int n){
    int ans=1;
    for(auto prime:primeNumbers){
        if(prime*prime>n)break; //loop till sqrt(n)
            if(n%prime==0){
                int count=1;
                while(n%prime==0){
                count++;
                n/=prime;
            }
            ans*=count;
        }
        
    }
    //Let assume n>1 and n=5. Then 5 has two divisors 5^0 and 5^1. So ans*=2 below
    if(n>1)ans*=2; //visualize the loop of line 30 for n=20 then you can understand it value
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    seive(1e6);
    int t;
    cin>>t;
    // divisors of 20=1,2,4,5,10,20
    // Total distinct divisors=6
    // 20=(2^2)*(5^1)
    // Now,(2+1)*(1+1)=3*2=6 //multiple of power+1
    while(t--){
        int n;
        cin>>n;
        cout<<NOD(n)<<endl;
    }
    //getting disting prime factors using harmonic mean
    
}
// Sample input:
// 3
// 4
// 5
// 6
// Output:
// 3
// 2
// 4
// Explanation:
// 4=1,2,4
// 5=1,5
// 6=1,2,3,6