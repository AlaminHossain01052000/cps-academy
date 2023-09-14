#include<bits/stdc++.h>
using namespace std;
const int N=110;
const int W=1e5+100;
int n,capacity;
int weight[N];
int value[N];
long long dp[N][W];
long long solve(int i,int currentWeight){
    if(i>n)return 0;
    if(dp[i][currentWeight]!=-1)return dp[i][currentWeight];
    long long ret1=0;
    long long ret2=0;
    if(currentWeight+weight[i]<=capacity)ret1=value[i]+solve(i+1,currentWeight+weight[i]);
    ret2=solve(i+1,currentWeight);
    return dp[i][currentWeight]=max(ret1,ret2);
}
int main(){
    cin>>n>>capacity;
    for(int i=1;i<=n;++i)cin>>weight[i]>>value[i];
    memset(dp,-1,sizeof(dp));
    cout<<solve(1,0)<<endl;
    // set<int> st;
    // cout<<st.first<<endl;
}