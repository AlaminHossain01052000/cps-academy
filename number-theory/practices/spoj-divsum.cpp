#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=500100;
signed main(){
    vector<int>sum(N,1);
    for(int i=2;i*i<N;++i){
        for(int j=i;j<N;j+=i){
            // dcount[j]++;
            if(i!=j){
                sum[j]+=i;
                if(j/i>sqrt(N)){
                    sum[j]+=(j/i);
                }
            }
        }
    }
    sum[1]=0;
    // for(int i=1;i<N;++i){
    //     int sum2=0;
    //     for(int j=1;j<i;++j){
    //         if(i!=j&&i%j==0)sum2+=j;
    //     }
    //     if(sum2!=sum[i]){
    //         cout<<i<<" "<<sum[i]<<" "<<sum2<<endl;
    //         return 0;
    //     }
    // }
    // return 0;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<sum[n]<<endl;
    }
}