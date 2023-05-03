#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int M=3*1e9;
const int N=1e7+10;
signed main(){
   int sum=0;
   int i=0;
   vector<int> v;
   while(sum<=M){
    v.push_back(sum);
    i++;
    sum+=i;
   }
   int t;
   cin>>t;
   while(t--){
    int y;
    cin>>y;
    int low=lower_bound(v.begin(),v.end(),y)-v.begin();
    if(v[low]==y)cout<<low<<endl;
    else cout<<"NAI\n";
   }
    
}