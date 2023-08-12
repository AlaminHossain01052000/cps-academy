#include<bits/stdc++.h>
using namespace std;
const int MX = 5e7+123;//It will decrease the memory limit by 2. If N=1e8 then take MX=1e8/2
bool seive[MX];
vector<int> prime;
 
void seiveGen(int limit) {
    limit += 100;
    int sqrtn = sqrt(limit);
    for(int i = 3; i <= sqrtn; i += 2) {
        if(!seive[i>>1]) {
            for(int j = i * i; j < limit; j += i + i) {
                seive[j>>1] = 1;
            }
        }
    }
    
    prime.push_back(2);
    for(int i = 3; i < limit; i += 2) {
        if(!seive[i>>1]) prime.push_back(i);
    }
}
signed main(){
    seiveGen(1e6);
    for(auto &p:prime){
        cout<<p<<" ";
        if(p>100)break;
    }
}