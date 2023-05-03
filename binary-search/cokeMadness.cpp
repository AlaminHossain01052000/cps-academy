#include <bits/stdc++.h>
using namespace std;
#define int long long int

int calc(int a,int b,int c,int x){
    return ((a*x*x)+(b*x)+c);
}
signed main() {
	int t;
    cin>>t;
    for(int p=1;p<=t;++p){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;++i)cin>>v[i];
        int ans=0;
        int total=0;
        for(int i=0;i<n;++i){
            if(total+v[i]<=0){
                // cout<<(((total+v[i])*-1)+1)<<endl;
                ans+=(((total+v[i])*-1)+1);
                total=1;
            }
            else total+=v[i];
        }
        // cout<<total<<endl;
        if(ans==0)cout<<"Scenario #"<<p<<": "<<ans+1<<endl;
        else cout<<"Scenario #"<<p<<": "<<ans<<endl;
    }
}