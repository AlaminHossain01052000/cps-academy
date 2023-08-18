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
    isPrime[2]=1;
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
vector<int> primeFactors(int n){
    vector<int> primeFacts;
    for(auto &p:primes){
        if(p*p>n)break;
        if(n%p==0){
            while(n%p==0){
                primeFacts.push_back(p);
                n/=p;
            }
        }
    }
    if(n>1)primeFacts.push_back(n);
    return primeFacts;
}
void recur(int i,vector<int>&factors,int limit,int currentValue,set<int> &values,map<int,bool> &mp){
    if(mp[currentValue])return;
    values.insert(currentValue);
    if(i>limit){
        return;
        
    }
    
    recur(i+1,factors,limit,currentValue*factors[i],values,mp);
    recur(i+1,factors,limit,currentValue,values,mp);
    

    // ans-=(factors[i]*n);
    // ans+=(factors[i]*n);
    // ans/=__gcd(factors[i],n);

}
void solve(){
    int n;
    cin>>n;
    if(n==1){
        cout<<1<<endl;
        return;
    }
    int ans=n;
    ans*=((2*n)+((n-1)*n));
    ans/=2;
    if(isPrime[n]){
        ans-=(n*n);
        ans+=n;
        cout<<ans<<endl;
        return;
    }
    auto factors=primeFactors(n);
    set<int> values;
    map<int,bool> mp;
    recur(0,factors,factors.size()-1,1,values,mp);
    for(auto &ele:values){
        if(ele==1||ele==n)continue;
        ans-=(ele*n);
        ans+=(ele*n);
        ans/=__gcd(ele,n);
    }
    ans-=(n*n);
    ans+=n;
    // ans/=n;
    cout<<ans<<endl;
}
signed main(){
    seive(1e6);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
