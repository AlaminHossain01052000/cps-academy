// https://www.spoj.com/problems/HS08PAUL/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e7+100;

bitset<N>isPrime;
vector<int> squares;

void calcSquare(){
    for(int i=1;i*i<N;++i){
        
            squares.push_back(i*i);
        
        // else break;
    }
}
void seive(){
    
    isPrime[2]=1;
    for(int i=3;i<N;i+=2)isPrime[i]=1;
    for(int i=3;i*i<N;i+=2){
        
        if(isPrime[i]){
           
            for(int j=i*i;j<N;j+=2*i){
                isPrime[j]=0;
            }
        }
    }

    // for(int i=3;i<N;i+=2)if(isPrime[i])primes.push_back(i);

}
signed main(){
    seive();
    calcSquare();
    // map<int,int>mp;
    vector<int>prefixSum(N,0);
    // cout<<squares.size()<<endl;
    for(int i=0;i<squares.size();++i){
        int x2=squares[i];
        for(int y=1;y*y*y*y<N;++y){
            int y4=y*y*y*y;
            if(x2+y4<N){
                if(isPrime[x2+y4]){
                    prefixSum[x2+y4]=1;
                    // mp[x2+y4]=1;
                }
            }
            else break;
        }
    }
    for(int i=1;i<N;++i)prefixSum[i]+=prefixSum[i-1];
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        cout<<prefixSum[n]<<endl;
        // int ans=0;
        // map<int,int>m;
        // set<pair<int,int>>st;
        // for(int y=1;y*y*y*y<=n;++y){
        //     for(int i=0;i<squares.size();++i){
        //         int x2=squares[i];
        //         int y4=y*y*y*y;
        //         if(x2+y4>n)break;
        //         if(isPrime[x2+y4]){
        //             st.insert(make_pair(sqrt(x2),y));
        //         }
        //     }
        // }
        // cout<<st.size()<<endl;
    }
    
}