#include<bits/stdc++.h>
using namespace std;
double eps=1e-12;
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
void  solve(int t){
    double l,n,c;
    cin>>l>>n>>c;
    double lPrime=(1.0+(n*c))*l;

    double low=0;
    double high=1e18;
    for(int i=1;i<=100;++i){
        double r=(low+high)/2.0;
        double assumedLPrime=2.0*r*(asin((l/(2.0*r))));
        if(assumedLPrime>lPrime){
            low=r;
        }
        else high=r;
    }   
    double r=low;
    double h=r-(sqrt(r*r-((l/2.0)*(l/2.0))));
    cout<<"Case "<<t<<": "<<fixed<<setprecision(10)<<h<<endl;
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin>>test;
    for(int t=1;t<=test;++t){
        solve(t);
    }
}

// Sample Input:
// 3
// 1000 100 0.0001
// 150 10 0.00006
// 10 0 0.001



// Sample Output:
// Case 1: 61.3289915
// Case 2: 2.2502024857
// Case 3: 0

