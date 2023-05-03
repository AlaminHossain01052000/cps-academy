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

/// cout<<*X.find_by_order(1)<<endl; // iterator to the k-th largest element // return the index of the 1 in the set
/// cout<<X.order_of_key(-5)<<endl;  // number of items in a set that are strictly smaller than our item

int main(){
    //given an array and some queries. In each query you will given an integer 'x'. You have to calculate the number of elements less than that given integer x in that array in O(logn)

    // suppose given array={1,2,4,6,6,9,11};
    // if x=6 then answer is 3 as there are 3 elements {1,2,4} less than x in that array. 
    // if x=11 then asnwer is 6. the elements are {1,2,4,6,6,9}

    int n;
    cin>>n;
    ordered_set ps; 
    //here ordered_set is a policy based data structure. We can use this here as we include the necessary header file above. Now it will treat like a multiset. If we use less then it will be a set, it we use greater then it will treated as a set of decreasing order. for more info watch "https://www.youtube.com/watch?v=t9-uFN23HjQ" of cps academy.
    // The insertion, erase, find etc. operation will take O(logn) complexity

    for(int i=1;i<=n;++i){
        int val;cin>>val;
        ps.insert(val);
    }
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        cout<<ps.order_of_key(x)<<endl;// ps.order_of_key(x) will return the number of items in a set or multiset that are strictly smaller than our item
    }
    //sample input
    // 7
    // 1 2 4 6 6 9 11
    // 10
    // 1
    // 2
    // 3
    // 4
    // 0
    // 6
    // 9
    // 11
    // 1000
    // 10

    //sample output
    // 0
    // 1
    // 2
    // 2
    // 0
    // 3
    // 5
    // 6
    // 7
    // 7


}