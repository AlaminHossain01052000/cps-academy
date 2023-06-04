// https://vjudge.net/problem/UVA-543
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<int>isPrime(N,1);
void seive(){
    isPrime[1]=0;
    isPrime[0]=0;
    for(int i=2;i<N;++i){
        if(isPrime[i]==1){
            for(int j=2*i;j<N;j+=i){
                isPrime[j]=0;
            }
        }
    }
}
int main(){
    seive();
    int n;
    cin>>n;
    while(n!=0){
        bool isPrinted=false;
        for(int i=3;i<=n;i+=2){
            if(isPrime[i]){
                int diff=n-i;
                if(isPrime[diff]){
                    cout<<n<<" = "<<i<<" + "<<diff<<endl;
                    isPrinted=true;
                    break;
                }
            }
        }
        if(!isPrinted){
            cout<<"Goldbach's conjecture is wrong.\n";
        }
        cin>>n;
    }
}