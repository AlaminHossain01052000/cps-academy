#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin>>q;
    while(q--){
        int n,k;
        cin>>n>>k;
        int x=0;
        int count=0;
        while(n){
            x+=2;
            count++;
            x%=n;
            if(x==0)x=n;
            if(k==count){
                cout<<x<<endl;
                break;
            }
        }
    }
}