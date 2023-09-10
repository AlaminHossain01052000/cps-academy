#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int h[N];
int n,k;
int dp[N];
int solve(int i){
    if(i==n)return 0;
    if(dp[i]!=-1)return dp[i];
    int x=INT_MAX;
    for(int j=1;j<=k;++j){
        if(i+j<=n)x=min(x,abs(h[i]-h[i+j])+solve(i+j));
    }
    return dp[i]=x;
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>h[i];
    memset(dp,-1,sizeof(dp));
    cout<<solve(1)<<endl;

}