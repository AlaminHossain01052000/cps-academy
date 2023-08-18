// https://algo.codemarshal.org/contests/icpc-dhaka-19-preli/problems/G
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e7+110;
vector<int> phi(N);
void phiHarmonicMean(int n){
    n+=100;
    for(int i=1;i<=n;++i){
        phi[i]=i;
    }
    for(int i=2;i<=n;++i){
        if(phi[i]==i){
            for(int j=i;j<=n;j+=i){
                phi[j]*=(i-1);
                phi[j]/=i;
            }
        }
        
    }
    for(int i=2;i<=n;++i)phi[i]+=phi[i-1];
}
signed main(){
    phiHarmonicMean(1e7);
    
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;++t){
        int n,p;
        cin>>n>>p;
        int low=1;
        int high=n;
        while(high-low>1){
            int mid=(low+high)>>1LL;
            if(phi[n/mid]>=p){
                low=mid;
            }
            else high=mid-1;
        }
        cout<<"Case "<<t<<": ";
        if(phi[n/high]>=p)cout<<high<<endl;
        else if(phi[n/low]>=p)cout<<low<<endl;
        else cout<<-1<<endl;
    }
}