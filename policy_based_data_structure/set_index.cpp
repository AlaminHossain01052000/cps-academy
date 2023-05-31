#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree< long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set; 
/// change ll to any data type
/// less_equal for multiset increasing order
/// less for set increasing order
/// greater_equal for multiset decreasing order
/// greater for set decreasing order

/// cout<<*X.find_by_order(1)<<endl; // return the index of the 1 in the set
/// cout<<X.order_of_key(-5)<<endl;  // number of items in a set that are strictly smaller than our item
int main(){
    //set
    ordered_set ps;
    ps.insert(2);
    ps.insert(2);
    ps.insert(3);
    ps.insert(6);
    ps.insert(4);
    ps.insert(5);
    
    ps.erase(4); //It will only work in set. For delete an element in multiset you have to find the iterator of that element . Example :
    // auto it=ps.upper_bound(4);// Here I am using upper bound and pbds is mental in the case of multiset and it return lower bound if I find upper bound and upper bound if i find lower bound
    // ps.erase(it);
   
    for(auto ele:ps)cout<<ele<<" ";cout<<endl;
    cout<<"Value at index 2 is : "<<*ps.find_by_order(2)<<endl;
    cout<<"Value at index 3 is : "<<*ps.find_by_order(3)<<endl;
    cout<<"Lower bound of 2 is : "<<*ps.lower_bound(2)<<endl;
    cout<<"Lower bound of 2 is : "<<*ps.lower_bound(4)<<endl;
    // set<int> s;
    // s.insert(2);
    // s.insert(3);
    // s.insert(4);
    // s.insert(8);
    
    
    // for(auto ele:s)cout<<ele<<" ";cout<<endl;
    // cout<<*lower_bound(5)<<endl;
}
