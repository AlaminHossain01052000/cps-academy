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
	int t;
    cin>>t;
    for(int p=1;p<=t;++p){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;++i)cin>>v[i];
        int low=0;
        int high=1e10+1;
        while(high-low>1){
            int mid=(low+high)/2;
            if(calc(v,mid)==true){
                high=mid;
            }
            else low=mid+1;
        }
        // cout<<low<<" "<<high<<endl;
        if(calc(v,low))cout<<low<<endl;
        else if(calc(v,high))cout<<high<<endl;
        // if(ans==0)cout<<"Scenario #"<<p<<": "<<ans+1<<endl;
        // else cout<<"Scenario #"<<p<<": "<<ans<<endl;
    }
}