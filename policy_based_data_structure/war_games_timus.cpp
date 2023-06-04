#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree< long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
// cout<<*X.find_by_order(1)<<endl;

int main(){
    fast
    int n,k;
    cin>>n>>k;
    ordered_set ps;
    for(int i=1;i<=n;++i){
        ps.insert(i);
    }
    cout<<*ps.find_by_order(k-1)<<" ";
    ps.erase(*ps.find_by_order(k-1));
    n--;
    int currentIndex=k-1;
    while(ps.size()>1){
        // int upojuktoIndex=(currentIndex+(k-1))%n;
        if(currentIndex+(k-1)>=n){
            int upojuktoIndex=currentIndex+(k-1);
            while(upojuktoIndex>=n){
                upojuktoIndex=upojuktoIndex-n;
            }
            cout<<*ps.find_by_order(upojuktoIndex)<<" ";
            ps.erase(*ps.find_by_order(upojuktoIndex));
            currentIndex=upojuktoIndex;
            n--;
            
        }
        else{
            cout<<*ps.find_by_order(currentIndex+(k-1))<<" ";
            ps.erase(*ps.find_by_order(currentIndex+(k-1)));
            n--;
            currentIndex=(currentIndex+(k-1))>=n?(currentIndex+(k-1))-n:(currentIndex+(k-1));
            

        }
    }
    if(ps.size()==1)
    cout<<*ps.find_by_order(0)<<endl;

}
