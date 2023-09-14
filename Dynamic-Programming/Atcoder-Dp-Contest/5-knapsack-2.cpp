#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=110;
const int maxprofit=1e5+100;
int weight[N];
int value[N];
int dp[N][maxprofit];
int n,capacity;
ll solve(int i,int currentProfit,int availableSpace){
    if(i>n)return 0;
    if(dp[i][currentProfit]!=-1)return dp[i][currentProfit];
    ll ret1=0;
    ll ret2=0;
    if(availableSpace-weight[i]>=0)ret1=value[i]+solve(i+1,currentProfit+value[i],availableSpace-weight[i]);
    ret2=solve(i+1,currentProfit,availableSpace);
    return dp[i][currentProfit]=max(ret1,ret2);
}
int main(){
    cin>>n>>capacity;
    for(int i=1;i<=n;++i)cin>>weight[i]>>value[i];
    memset(dp,-1,sizeof(dp));
    cout<<solve(1,0,capacity)<<endl;
}
