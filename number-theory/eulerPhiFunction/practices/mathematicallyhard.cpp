// https://lightoj.com/problem/mathematically-hard
// If we need to calculate phi of numbers from a range [a,b] such that for [1,6] the phi(1)=0,phi(2)=1,phi(3)=2,phi(4=2,phi(5)=4,phi(6)=2 then phi using harmonic min is useful

#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long int
const int N=5e6+100;
vector<int> phi(N);
signed main(){
    int n=5e6;
    for(int i=1;i<=n;++i)phi[i]=i;
    for(int i=2;i<=n;++i){
        if(phi[i]==i){
            for(int j=i;j<=n;j+=i){
                phi[j]*=(i-1);
                phi[j]/=i;
            }
        }
    }
    for(int i=1;i<=n;++i)phi[i]*=phi[i];
    for(int i=1;i<=n;++i)phi[i]+=phi[i-1];
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;++t){
        int a,b;
        cin>>a>>b;
        int ans=phi[b]-phi[a-1];
        cout<<"Case "<<t<<": ";
        cout<<ans<<endl;
        
    }
}
// Input:
// 5
// 1
// 2
// 3
// 4
// 5

// Output:
// 1
// 1
// 2
// 2
// 4