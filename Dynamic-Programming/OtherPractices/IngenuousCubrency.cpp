// https://vjudge.net/problem/uva-11137
// https://www.youtube.com/watch?v=xYuVRF8TYTY&list=PLoa_roVVsxA1hNTFt0fO9-DNsX_STaR3h&index=12
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+100;
int coin[22];
long long dp[22][N];
long long solve(int i,int n){
    if(i==22||n==0)return (n==0);
    if(dp[i][n]!=-1)return dp[i][n];
    long long ret=0;
    for(int j=0;j<=n;++j){
        if(n-(j*coin[i])>=0){
            ret+=solve(i+1,n-(j*coin[i]));
        }
        else break;
    }
    return dp[i][n]=ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=21;++i)coin[i-1]=i*i*i;
    int n;
    while(cin>>n){
        // if(n==0)break;
        cout<<solve(0,n)<<endl;
    }
}