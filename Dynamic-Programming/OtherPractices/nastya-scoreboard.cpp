// https://codeforces.com/contest/1341/problem/D
#include<bits/stdc++.h>
using namespace std;
const int N=2e3+100;
struct info{
    int i,c,ans;
    info(){};
    info(int a,int b,int d){
        i=a;
        c=b;
        ans=d;
    }
}dir[N][N];
int n,k;
vector<string> v(N);
int dp[N][N];
vector<string> digitString={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int getValue(string s1,string s2){
    int cost=0;
    for(int i=0;i<7;++i){
        if(s1[i]=='1'&&s2[i]=='0')return -1;
        if(s1[i]=='0'&&s2[i]=='1')cost++;

    }
    return cost;
}
int solve(int i,int c){
    if(i==n)return (c==k);
    if(dp[i][c]!=-1)return dp[i][c];
    int ret=0;
    for(int j=9;j>=0;--j){
        string s1=v[i];
        string s2=digitString[j];
        int cost=getValue(s1,s2);
        if(cost==-1)continue;
        if(c+cost<=k){
            ret|=solve(i+1,c+cost);
            if(ret==1){
                dir[i][c]=info(i+1,c+cost,j);
                break;
            }
        }
    }
    return dp[i][c]=ret;
}
void print(int i,int c){
    if(dir[i][c].ans==-1)return;
    cout<<dir[i][c].ans;
    print(dir[i][c].i,dir[i][c].c);
}
int main(){
   cin>>n>>k;
   for(int i=0;i<n;++i)cin>>v[i];
//    return 0;
   memset(dp,-1,sizeof(dp));
   for(int i=0;i<N;++i){
    for(int j=0;j<N;++j){
        dir[i][j]=info(-1,-1,-1);
    }
   }
   if(solve(0,0)){
    // cout<<1<<endl;
    // return 0;
    print(0,0);
   }
   else cout<<-1;
   cout<<endl;
}