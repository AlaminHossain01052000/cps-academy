#include<bits/stdc++.h>
using namespace std;
const int N=1e7+100;
vector<vector<int>>divisorsContainer(N+1);
void printDivisors(){
    for(int i=1;i<N;++i){
        for(int j=i;j<N;j+=i){
            divisorsContainer[j].push_back(i);
        }
    }
}
int main(){
    printDivisors();
    for(int i=1;i<=1e6;++i){
        for(auto &ele:divisorsContainer[i]){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}