// https://toph.co/p/life-of-phi
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e6+100;
vector<int> phi(N);
vector<int> ans(N);
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=1;i<N;++i)phi[i]=i;
    for(int i=2;i<N;++i){
        if(phi[i]==i){
            for(int j=i;j<N;j+=i){
                phi[j]-=phi[j]/i;
                // phi[j]/=i;
            }
        }
    }
    // for 10 1+2+3+....+9 = (n*(n+1))/2;
    // Sum of co-primes of n=(n*phi[n])/2;
    for(int i=1;i<N;++i){
        int y=((i-1)*i)>>1;
        int x=(phi[i]*i)>>1;
        ans[i]=y-x;
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<ans[n]<<endl;
    }
}