#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool calc(vector<int>&v,int n){
    int total=n;
    for(auto ele:v){
        total+=ele;
        if(total<=0)return false;
    }
    return true;
}
signed main() {
	int t=1;
    // cin>>t;
    for(int p=1;p<=t;++p){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;++i)cin>>v[i];
        vector<int> prefixSum(n);
        prefixSum[0]=v[0];
        for(int i=1;i<n;++i)prefixSum[i]=v[i]+prefixSum[i-1];
        int m;
        cin>>m;
        while(m--){
            int j;
            cin>>j;
            cout<<(lower_bound(prefixSum.begin(),prefixSum.end(),j)-prefixSum.begin())+1<<endl;
        }
    }
}