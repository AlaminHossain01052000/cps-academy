#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,totalSpace;
int space[N];
int funValue[N];
int dp[N][101000];
long long knapsack(int i,int currentSpace){
    if(i>n)return 0;
    if(dp[i][currentSpace]!=-1)return dp[i][currentSpace];
    long long ret1=0;
    long long ret2=0;
    if(currentSpace+space[i]<=totalSpace)ret1=funValue[i]+knapsack(i+1,currentSpace+space[i]);
    ret2=knapsack(i+1,currentSpace);
    return dp[i][currentSpace]=max(ret1,ret2);
}
void solve(int t){
    cin>>n>>totalSpace;
    for(int i=1;i<=n;++i)cin>>space[i]>>funValue[i];
    memset(dp,-1,sizeof(dp));
    cout<<"Case "<<t<<": "<<knapsack(1,0)<<endl;
}
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;++i)solve(i);
}