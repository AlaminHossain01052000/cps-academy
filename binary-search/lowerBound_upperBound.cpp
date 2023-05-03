#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v={1,2,4,4,4,7};
    int l=lower_bound(v.begin(),v.end(),3)-v.begin();
    cout<<l<<endl;
    cout<<upper_bound(v.begin(),v.end(),3)-v.begin()<<endl;
}