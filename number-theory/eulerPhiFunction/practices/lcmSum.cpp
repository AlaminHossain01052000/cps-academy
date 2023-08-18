// https://forthright48.com/spoj-lcmsum-lcm-sum
// https://www.spoj.com/problems/LCMSUM/

#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e6+110;
vector<int> phi(N);
vector<int> temp(N,0);
void phiUsingHarmonic(){
    for(int i=1;i<N;++i)phi[i]=i;
    for(int i=2;i<N;++i){
        if(phi[i]==i){
            for(int j=i;j<N;j+=i){
                phi[j]*=(i-1);
                phi[j]/=i;
            }
        }
    }
}
void divisorUsingHarmonicMean(){

    for(int i=1;i<N;++i){
        for(int j=i;j<N;j+=i){
            temp[j]+=(phi[i]*i);
        }
    }
}
void solve(){
    int n;
    cin>>n;
    int ans=temp[n]+1;
    ans*=n;
    ans>>=1;
    cout<<ans<<endl;
}
signed main(){
    phiUsingHarmonic();
    divisorUsingHarmonicMean();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
