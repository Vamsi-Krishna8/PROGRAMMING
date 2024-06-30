class Solution {
public:
    int check(int mid,vector<int> &nums){
        int count=1;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                count++;
                sum=nums[i];
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int lo=*max_element(nums.begin(),nums.end());
        int hi=1e9;
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int res=check(mid,nums);
            if(res>k) lo=mid+1;
            else{
                ans=mid;
                hi=mid-1;
            }
        }
        return ans;   
    }
};