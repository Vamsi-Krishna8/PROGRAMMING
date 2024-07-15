bool check(int mid,vector<int> nums,int maxOp){
  int n=nums.size();
  int count=0;
  for(auto x:nums){
      if(x>mid){
          count+=(x-1)/mid;
      }
  }
  return count<=maxOp;
}
int minimumSize(vector<int>& nums, int maxOp) {
  int lo=1,hi=9;
  int ans=0;
  while(lo<=hi){
      int mid=lo+(hi-lo)/2;
      if(check(mid,nums,maxOp)){
          ans=mid;
          hi=mid-1;
      }
      else lo=mid+1;
  }
  return ans;
}