#include<bits/stdc++.h>
using namespace std;
double eps=1e-12;
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
void  solve(int t){
    double x,y,c;
    cin>>x>>y>>c;
    double low=0;
    double high=min(x,y);
    for(int i=1;i<=110;++i){
        double d=(low+high)/2.0;
        double h1=sqrt((x*x)-(d*d));
        double h2=sqrt((y*y)-(d*d));

        double h=(h1*h2)/(h1+h2);
        if(abs(h-c)<eps){
            cout<<"Case "<<t<<": "<<fixed<<setprecision(10)<<d<<endl;
            return;
        }
        else if(h>c){
            low=d;
        }
        else{
            high=d;
        }
    }
   
    cout<<"Case "<<t<<": "<<fixed<<setprecision(10)<<low<<endl;
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
// 4
// 30 40 10
// 12.619429 8.163332 3
// 10 10 3
// 10 10 1


// Sample Output:
// Case 1: 26.0328775442
// Case 2: 6.99999923
// Case 3: 8
// Case 4: 9.797958971
