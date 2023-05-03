#include<bits/stdc++.h>
using namespace std;
const double eps=1e-12;
long long int floorSqrt(long long int x) 
{
        // Your code goes here 
        double low=0;
        double high=x+0.0;
        for(int i=1;i<=100;++i){
            double mid=(low+high)/2.0;
            if(mid*mid>x)high=mid;
            else low=mid;
        }
        return floor(low);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        cout<<floorSqrt(x)<<endl;
    }
}