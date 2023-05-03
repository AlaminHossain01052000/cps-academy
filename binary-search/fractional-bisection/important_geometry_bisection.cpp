// https://lightoj.com/problem/triangle-partitioning
#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;cin>>test;
    for(int t=1;t<=test;++t){
        double ab,ac,bc,ratio;
        cin>>ab>>ac>>bc>>ratio;
        double low=0;
        double high=ab;
        for(int i=1;i<=100;++i){
            double ad=(low+high)/2.0;
            double ae=(ac*ad)/ab;
            double de=(bc*ad)/ab;
            
            double p1=(ad+de+ae)/2;
            double p2=(ab+bc+ac)/2;
            
            double areaADE=sqrt(p1*(p1-ad)*(p1-de)*(p1-ae));
            double areaABC=sqrt(p2*(p2-ab)*(p2-bc)*(p2-ac));
            double areaBDEC=areaABC-areaADE;
            
            double assumedRatio=areaADE/areaBDEC;
            if(assumedRatio>ratio){
                high=ad;
            }
            else low=ad;
            
            
        }
        cout<<"Case "<<t<<": "<< fixed << setprecision(10)<<low<<endl;
    }
        
}
// Sample Input
// 4
// 100 100 100 2
// 10 12 14 1
// 7 8 9 10
// 8.134 9.098 7.123 5.10

// Sample Output
// Case 1: 81.6496580
// Case 2: 7.07106781
// Case 3: 6.6742381247
// Case 4: 7.437454786
