#include<bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int m;
    cin>>m;
    vector<int> q(m);
    for(int i=0;i<m;i++) cin>>q[i];
    for(int i=1;i<n;i++){
        v[i]+=v[i-1];
    }
    for(int i=0;i<m;i++){
        int val=lower_bound(v.begin(),v.end(),q[i])-v.begin();
        cout<<val+1<<endl;
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