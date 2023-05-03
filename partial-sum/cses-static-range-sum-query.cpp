#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;vector<int>v(n+1);
    for(int i=1;i<=n;++i)cin>>v[i];
    vector<long long>prefixSum(n+1);
    prefixSum[0]=0;
    for(int i=1;i<=n;++i){
        prefixSum[i]=prefixSum[i-1]+v[i];
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<prefixSum[b]-prefixSum[a-1]<<endl;
    }

}