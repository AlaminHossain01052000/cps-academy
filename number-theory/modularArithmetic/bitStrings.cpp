// https://vjudge.net/problem/UVA-374
// https://cses.fi/problemset/task/1617
#include<bits/stdc++.h>
using namespace std;
#define int long long int
int binaryExponentitaion(int a,int b,int m){
    a=a%m;
    int ans=1;
    while(b>0){
        if(b&1)ans=(ans*1LL*a)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    cout<<binaryExponentitaion(2,n,1e9+7);
}