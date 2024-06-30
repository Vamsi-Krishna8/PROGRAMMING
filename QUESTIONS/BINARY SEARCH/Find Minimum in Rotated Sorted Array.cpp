class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans=INT_MAX;
        int lo=0,hi=nums.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[lo]<=nums[mid]){
                ans=min(nums[lo],ans);
                lo=mid+1;
            }
            else{
                ans=min(nums[mid],ans);
                hi=mid-1;
            }
        }
        return ans;
    }
};