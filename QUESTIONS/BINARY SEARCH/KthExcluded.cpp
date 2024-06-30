#include<bits/stdc++.h>
using namespace std;
#define int long long int

int check(int tar,vector<int> &v){
    int n=v.size();
    int lo=0,hi=n;
    int ans=n;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(v[mid]-(mid+1)<tar){
            lo=mid+1;
        }
        else{
            ans=mid;
            hi=mid-1;
        }
    }
    return ans;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<int> q(m);
    for(int i=0;i<m;i++) cin>>q[i];

    for(int i=0;i<m;i++){
        int res=check(q[i],v);
        cout<<res+q[i]<<endl;
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