#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;


using namespace __gnu_pbds;

typedef tree< long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
int main(){
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;++t){
        string s;
        int k;
        cin>>s>>k;
        int n=s.size();
         vector<long long>sum0(n+1,0);
        vector<long long>sum1(n+1,0);

        for(int i=0;i<n;++i){
            sum0[i+1]=sum0[i]+(s[i]=='0');
            sum1[i+1]=sum1[i]+(s[i]=='1');
        }

        map<int,int>m;

        ordered_set ps;
        ps.insert(0);
        m[0]++;
        long long ans=0;
        for(int i=1;i<=n;++i){
            long long d1=sum0[i]-(k*sum1[i]);
            ans+=ps.order_of_key(d1);
            ans+=m[d1];

            ps.insert(d1);
            m[d1]++;

        }
        cout<<"Case "<<t<<": "<<ans<<endl;

    }
}