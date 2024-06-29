#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool check(int mid,int n){
    return mid*(mid+1)/2 <=n;
}
void solve(){
    int n;
    cin>>n;
    int lo=1,hi=2e9;
    int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(check(mid,n+1)){
            ans=mid;
            lo=mid+1;
        }
        else hi=mid-1;
    }
    cout<<n+1-ans<<endl;  
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