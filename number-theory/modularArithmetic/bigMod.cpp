// https://vjudge.net/problem/UVA-374
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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,b,m;
    while(cin>>a>>b>>m){
        
        
        cout<<binaryExponentitaion(a,b,m)<<endl;
    }
}