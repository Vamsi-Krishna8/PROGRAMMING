#include<bits/stdc++.h>
using namespace std;
#define int long long int
bool check(int val,int n,int k){
    return (val-val/n)>=k;
}
void solve(){
    int n,k;
    cin>>n>>k;
    int lo=1,hi=1;
    int ans=-1;

    while(!check(hi,n,k)){
        hi*=2;
    }
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(check(mid,n,k)){
            ans=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }
    cout<<ans<<endl;   
}
int32_t main(){
    int t;
    t=1;
    cin>>t;
    while(t--){

        // cout<<t;
        solve();
    }
    return 0;
}