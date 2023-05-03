#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e9+1;

bool calc(vector<int>&v,int unit,int maxCity){
    int position=v[0]+unit;
    maxCity--;
    
    for(int i=1;i<v.size();++i){
        if(abs(v[i]-position)>unit){
            if(maxCity==0)return false;
            position=v[i]+unit;
            maxCity--;
        }
    }
    
    return true;
    
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int t;
    cin>>t;
    for(int p=1;p<=t;++p){
        int n,m,k;
        cin>>n>>m>>k;
        vector<int>v(m);
        for(int i=0;i<m;++i)cin>>v[i];
        int low=0;
        int high=n;
        int mid;
        while(high-low>1){
            mid=(low+high)/2;
            if(calc(v,mid,k)){
                high=mid;
            }
            else low=mid+1;
        }
        // cout<<low<<" "<<high<<endl; 
        // Case 1: 2
        if(calc(v,low,k))cout<<"Case "<<p<<": "<<low<<endl;
        else cout<<"Case "<<p<<": "<<high<<endl;
    }
}