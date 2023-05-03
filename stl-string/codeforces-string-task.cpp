#include<bits/stdc++.h>
using namespace std;
int main(){
    int t=1;
    // cin>>t;
    while(t--){
        string s;
        cin>>s;
        string ans="";
        for(int i=0;i<s.length();++i){
            if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='y'&&s[i]!='o'&&s[i]!='u'&&s[i]!='A'&&s[i]!='E'&&s[i]!='I'&&s[i]!='O'&&s[i]!='U'&&s[i]!='Y'){
                ans+='.';
                if(s[i]<97){
                    ans+=(char)(s[i]+32);
                }
                else{
                    ans+=s[i];
                }
                
            }
        }
        cout<<ans<<endl;
    }
}