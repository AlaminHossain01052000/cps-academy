#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e7+10;
vector<int>dcount(N,0);
signed main(){

    for(int i=1;i<N;++i)dcount[i]=0;
    for(int i=1;i<N;++i){
        for(int j=i;j<N;j+=i){
            dcount[j]++;
        }
    }
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;++i){
        ans+=(i*dcount[i]);
    }
    cout<<ans<<endl;
}