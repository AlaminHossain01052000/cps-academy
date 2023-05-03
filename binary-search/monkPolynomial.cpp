#include <bits/stdc++.h>
using namespace std;
#define int long long int

int calc(int a,int b,int c,int x){
    return ((a*x*x)+(b*x)+c);
}
signed main() {
	int t;
    cin>>t;
    while(t--){
        int a,b,c,k;
        cin>>a>>b>>c>>k;
        int low=0;
        int high=1e6;
        while(high-low>1){
            int mid=(low+high)/2;
            if(calc(a,b,c,mid)>=k){
                high=mid;
            }
            else low=mid+1;
        }
        if(calc(a,b,c,low)>=k)cout<<low<<endl;
        else cout<<high<<endl;
    }
}