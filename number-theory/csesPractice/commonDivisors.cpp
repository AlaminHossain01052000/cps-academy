#include<bits/stdc++.h>
using namespace std;
int main(){

    
    int n;
    cin>>n;
    vector<int>v(n);
    vector<int>m(1e6+1);
    for(int i=0;i<n;++i){
        cin>>v[i];
        m[v[i]]++;
    }  
    int maxi=*max_element(v.begin(),v.end());
    // int ans=1;
    for(int i=maxi;i>=2;--i){
        int count=0;
        for(int j=i;j<=maxi;j+=i){
            count+=m[j];
            if(count>=2){
                cout<<i<<endl;
                return 0;
            }
        }
    }
    cout<<1<<endl;
    // cout<<ans<<endl;
}