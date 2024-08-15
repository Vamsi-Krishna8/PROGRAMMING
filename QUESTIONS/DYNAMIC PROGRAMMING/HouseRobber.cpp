//Memo

class Solution {
public:
    int dp[101];

    int solve(int i,vector<int> &nums){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int steal=nums[i]+solve(i+2,nums);
        int skip=solve(i+1,nums);
        return dp[i]=max(steal,skip);

    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
    }
};

//TABULATION

//dp[i]=> max stolen money till house i

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<=n;i++){
            dp[i]=max(nums[i-1]+dp[i-2],dp[i-1]);
        }
        return dp[n];
    }
};