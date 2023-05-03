#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;++i)cin>>arr[i];
    
    while(q--){
        int x;
        cin>>x;
        int lo=lower_bound(arr,arr+n,x)-arr;
        if(lo==n)cout<<-1<<endl;
        else cout<<lo<<endl;
        
    }
    
}