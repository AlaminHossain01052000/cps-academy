// https://lightoj.com/problem/false-ordering
#include<bits/stdc++.h>
using namespace std;
int NOD[1010];
bool cmp(pair<int,int>p1,pair<int,int>p2){
    if(p1.first==p2.first)return p1.second>p2.second;
    return p1.first<p2.first;
}
signed main(){
    
    for(int i=1;i<=1000;++i){
        for(int j=i;j<=1000;j+=i){
            NOD[j]++;
        }
    }
    vector<pair<int,int>>v;
    for(int i=1;i<=1000;++i){
        v.push_back({NOD[i],i});
    }   
    sort(v.begin(),v.end(),cmp);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;++tc){
        int n;
        cin>>n;
        cout<<"Case "<<tc<<": "<<v[n-1].second<<endl;
    }
}