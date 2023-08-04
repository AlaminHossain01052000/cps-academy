// https://forthright48.com/divisor-summatory-function
#include<bits/stdc++.h>
using namespace std;
#define int long long int
// snod(5)=nod(1)+nod(2)+nod(3)+n(4)+n(5)=1+2+2+3+2=10
// Formula: snod(5)=((n/1)-1+(n/2)/2)*2+sqrt(n)//just a loop from 1 to sqrt(n) and find all divisors pair such that a<b. Then number of a>b=2*(a<b) and numberOf(a==b)=sqrt(n)
// for snod=5, 
// a<b==>(1,2),(1,3),(1,4),(1,5)=4
// a>b==>(2,1),(3,1),(4,1),(5,1)=4
// a==b==>(2,2),(1,1)=2
// so(a<b+a>b+a==b)=(4+4+2)=10 it is the snod of 5
int snod(int n){
    int sq=sqrt(n);
    int ans=0;
    for(int i=1;i*i<n;++i)
        ans+=((n/i)-i);
    
    return (ans*2)+sq;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<snod(n)<<endl;
    }
    
}
// input:
// 4
// 5
// 10
// 3
// 4
// output:
// 10
// 27
// 5
// 8