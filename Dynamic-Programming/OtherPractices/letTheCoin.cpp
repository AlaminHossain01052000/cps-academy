// https://vjudge.net/problem/uva-357
// https://www.youtube.com/watch?v=xYuVRF8TYTY&list=PLoa_roVVsxA1hNTFt0fO9-DNsX_STaR3h&index=12
#include<bits/stdc++.h>
using namespace std;
const int N=3e4+100;
long long dp[6][N];
int coin[]={1,5,10,25,50};
long long solve(int i,int n){
    if(i==5||n==0)return (n==0);
    if(dp[i][n]!=-1)return dp[i][n];
    long long ret=0;
    for(int j=0;j<=n;++j){
        if(n-(j*coin[i])>=0)
            ret+=solve(i+1,n-(j*coin[i]));
        else break;
    }
    return dp[i][n]=ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp,-1,sizeof(dp));
    
    int n;
    while(cin>>n){
        // if(n==0)break;
        long long y=solve(0,n);
        // cout<<y<<endl;
        if(y!=1LL){
            cout<<"There are "<<y<<" ways to produce "<<n<<" cents change.\n";
        }
        else{
            cout<<"There is only 1 way to produce "<<n<<" cents change.\n";
        }
    }
}