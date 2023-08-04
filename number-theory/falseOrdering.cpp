// https://lightoj.com/problem/false-ordering
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e3+10;
vector<int>primes;
bitset<N>isPrime;//It is 32 times memory saving
void seive(){
    isPrime[1]=false;
    isPrime[0]=false;
    primes.push_back(2);
    for(int i=3;i<N;i+=2)isPrime[i]=1;//all evens are 0
    for(int i=3;i*i<N;i+=2){
        
        if(isPrime[i]){
           
            for(int j=i*i;j<N;j+=2*i){
                isPrime[j]=0;
            }
        }
    }

    for(int i=3;i<N;i+=2)if(isPrime[i])primes.push_back(i);

}
int NOD(int n){
    int ans=1;
    for(auto prime:primes){
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
    seive();
       vector<int>v[100];
    for(int i=1000;i>=1;--i){
        int x=NOD(i);
        v[x].push_back(i);
    }
    vector<int>ans;
    for(int i=0;i<100;++i){
        if(v[i].size()){
            for(auto ele:v[i]){
            ans.push_back(ele);
        }
        }
        
    }
    int t;
    cin>>t;
    for(int tc=1;tc<=t;++tc){
        int n;
        cin>>n;
        cout<<"Case "<<tc<<": "<<ans[n-1]<<endl;
    }
}