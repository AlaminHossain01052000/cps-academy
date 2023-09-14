#include<bits/stdc++.h>
using namespace std;
const int N=2001;
int n,capacity;
int weight[N];
int value[N];
int dp[N][N];
long long solve(int i,int currentWeight){
    if(i>n)return 0;
    return dp[i][currentWeight]=dp[i][currentWeight]!=-1?dp[i][currentWeight]:(max(solve(i+1,currentWeight),currentWeight+weight[i]<=capacity?value[i]+solve(i+1,currentWeight+weight[i]):0));
}
int main(){
    cin>>capacity>>n;
    for(int i=1;i<=n;++i)cin>>weight[i]>>value[i];
    memset(dp,-1,sizeof(dp));
    cout<<solve(1,0)<<endl;
}