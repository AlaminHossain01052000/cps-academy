#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int vacation[N][4];
int dp[N][4];
int n;
int solve(int dayNo,int currentKaj){
    if(dayNo>n)return 0;
    if(dp[dayNo][currentKaj]!=-1){
       return dp[dayNo][currentKaj];

    }
    int ret=INT_MIN;
    if(currentKaj!=1)ret=max(ret,solve(dayNo+1,1));
    if(currentKaj!=2)ret=max(ret,solve(dayNo+1,2));
    if(currentKaj!=3)ret=max(ret,solve(dayNo+1,3));
    // return dp[dayNo][currentKaj]=(ret+vacation[dayNo][currentKaj]);
    return dp[dayNo][currentKaj]=(ret+vacation[dayNo][currentKaj]);


    // for(int i=1;i<=3;++i){
    //     if(previousIndex!=i){
    //         // if(dp[dayNo+1][i]==-1) ret=max(ret,solve(dayNo+1,i)+vacation[dayNo][i]);
    //         dp[dayNo][i]=vacation[dayNo][i]+solve(dayNo+1,i);
    //     }
    // }
   

}
int main(){
    
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=3;++j)cin>>vacation[i][j];
    }
    int x=solve(0,0);
    cout<<x<<endl;
}