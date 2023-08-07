// https://lightoj.com/problem/combinations
// https://vjudge.net/problem/UVA-374
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
//modular arithmetic starts here
const long long int MOD=1000003;
inline void normal(long long &a) { a %= MOD; (a < 0) && (a += MOD); }
inline long long modMul(long long a, long long b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline long long modAdd(long long a, long long b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline long long modSub(long long a, long long b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline long long modPow(long long b, long long p) { long long r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline long long modInverse(long long a) { return modPow(a, MOD-2); }
inline long long modDiv(long long a, long long b) { return modMul(a, modInverse(b)); }
//modular arithmetic ends here

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    vector<ll>fact(1e6+1);
    vector<ll>invrs(1e6+1);
    fact[0]=1;
    for(ll i=1;i<=1e6;++i){
        fact[i]=modMul(fact[i-1],i);
        invrs[i]=modInverse(i);
    }
    ll tc=1;
    while(tc<=t){
        ll n,k;
        cin>>n>>k;
        // cout<<fact[n]<<endl;
        cout<<"Case "<<tc<<": ";
        cout<<modDiv(fact[n],(modMul(fact[n-k],fact[k])))<<endl;
        tc++;
    }
}
