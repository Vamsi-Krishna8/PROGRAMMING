bool check(int mid,vector<int> &arr,int m){
  int sum=0;
  int count=1;
  for(int i=0;i<n;i++){
      if(sum+v[i]<=mid){
          sum+=v[i];
      }
      else{
          count++;
          sum=v[i];
      }
  }
  return count<=mid;
}
int findPages(vector<int>& arr, int n, int m) {
  // Write your code here.
  int maxi=*max_element(arr.begin(),arr.end());
  int sum=accumulate(arr.begin(),arr.end());
  int lo=maxi,hi=sum,ans=-1;
  while(lo<=hi){
      int mid=lo+(hi-lo)/2;
      if(check(mid,arr,m)){
          ans=mid;
          hi=mid-1;
      }
      else lo=mid+1;
  }
  return ans;
}