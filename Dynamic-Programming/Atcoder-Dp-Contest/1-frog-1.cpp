#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int h[N];
int n;
int dp[N];
int solve(int i){
    if(i==n)return 0;
    if(dp[i]!=-1)return dp[i];
    int x=INT_MAX;
    int y=INT_MAX;
    if(i+1<=n)x=abs(h[i]-h[i+1])+solve(i+1);
    if(i+2<=n)y=abs(h[i]-h[i+2])+solve(i+2);
    return dp[i]=min(x,y);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;++i)cin>>h[i];
    memset(dp,-1,sizeof(dp));
    cout<<solve(1)<<endl;

}