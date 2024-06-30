#include<bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> v(n),q(m);
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<m;i++) cin>>q[i];
    sort(v.begin(),v.end());
    vector<int> pref(n);
    pref[0]=v[0];
    for(int i=1;i<n;i++){
        pref[i]=pref[i-1]+v[i];
    }
    for(int i=0;i<m;i++){
        int ans=0;
        int idx=upper_bound(v.begin(),v.end(),q[i])-v.begin();
        ans+=abs(pref[idx-1]-idx*q[i]);
        ans+=abs(pref[n-1]-pref[idx-1]-(n-idx)*q[i]);
        cout<<ans<<endl;
    }   
}
int32_t main(){
    int t;
    t=1;
    // cin>>t;
    while(t--){

        // cout<<t;
        solve();
    }
    return 0;
}