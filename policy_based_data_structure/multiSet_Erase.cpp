#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree< long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set; 
/// change ll to any data type
/// less_equal for multiset increasing order
/// less for set increasing order
/// greater_equal for multiset decreasing order
/// greater for set decreasing order

/// cout<<*X.find_by_order(1)<<endl; // return the value of the  index 1 of the multiset
/// cout<<X.order_of_key(-5)<<endl;  // number of items in a set that are strictly smaller than our item
int main(){
    //set
    ordered_set ps;
    ps.insert(2);
    ps.insert(2);
    ps.insert(3);
    ps.insert(6);
    ps.insert(4);
    ps.insert(4);
    ps.insert(5);
    
    
   
    for(auto ele:ps)cout<<ele<<" ";cout<<endl;
    //"*ps.upper_bound(x)" function of policy based data structure give output of lower bound of x in that multiset. On the other hand,  "*ps.lower_bound(x)" function of policy based data structure give output of upper bound of x in that multiset.
    //It works fine in set of pbds but what the fuck is multiset!!!

    cout<<"Lower bound of 4 is :"<<*ps.upper_bound(4)<<endl;
    cout<<"Upper bound of 4 is :"<<*ps.lower_bound(4)<<endl;
    cout<<"Element at index 2 is "<<*ps.find_by_order(2)<<endl;

    //Let's erase an element from the pbds multiset and print the multiset again

    auto it=ps.upper_bound(4);
    if(it!=ps.end()&&*it==4)ps.erase(it);
    for(auto ele:ps)cout<<ele<<" ";cout<<endl;
}

