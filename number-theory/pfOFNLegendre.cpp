#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
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
vector<pair<int,int>> pfOfFactorial(int n){
    vector<pair<int,int>> ret;
    for(auto &p:primes){
        if(p>n)break;
        int count=0;
        int temp=n;
        while(temp>0){
            count+=(temp/p);
            temp/=p;
            
        }
        ret.push_back({p,count});
        
    }
    return ret;

}
int main(){
    seive(1e6);
    int n;
    while(cin>>n){
        auto pfactors=pfOfFactorial(n);
        cout<<"Prime factors of "<<n<<"! => \n";
        for(auto &ele:pfactors){
            cout<<ele.first<<" ^ "<<ele.second<<endl;
        }
        cout<<endl;
    }
}