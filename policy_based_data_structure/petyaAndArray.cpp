// https://codeforces.com/problemset/problem/1042/D
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree< ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update > ordered_set; 
/// change ll to any data type
/// less_equal for multiset increasing order
/// less for set increasing order
/// greater_equal for multiset decreasing order
/// greater for set decreasing order

/// cout<<*X.find_by_order(1)<<endl; // iterator to the k-th largest element
/// cout<<X.order_of_key(-5)<<endl;  // number of items in a set that are strictly smaller than our item

int main(){
    fast
    ll n,t;cin>>n>>t;
    vector<ll> v(n+1);
    for(int i=1;i<=n;++i)cin>>v[i];

    vector<ll> prefixSum(n+1,0);
    for(int i=1;i<=n;++i)prefixSum[i]=prefixSum[i-1]+v[i];

    map<ll,ll> cnt;
    ordered_set ps;
    ps.insert(0); //As prefixSum[0]=0
    cnt[0]++;
    ll ans=0;
    for(int i=1;i<=n;++i){
        ll numberOfElements=i;
        ll numberOfLesserElements=ps.order_of_key(prefixSum[i]-t);
        ll numnberOfEqualElements=cnt[prefixSum[i]-t];

        ans+=i-numberOfLesserElements-numnberOfEqualElements;

        ps.insert(prefixSum[i]);
        cnt[prefixSum[i]]++;
    }
    cout<<ans<<endl;
}