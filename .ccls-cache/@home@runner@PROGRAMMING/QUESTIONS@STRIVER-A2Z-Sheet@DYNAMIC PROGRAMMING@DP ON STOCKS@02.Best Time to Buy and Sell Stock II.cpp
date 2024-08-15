//Memo

class Solution {
public:
    int dp[30001][2];
    int n;
    int solve(vector<int> &prices,int idx,int buy){
        if(idx>=n) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];

        long profit=0;
        if(buy){
            profit=max(-prices[idx]+solve(prices,idx+1,0),solve(prices,idx+1,1));
        }
        else{
            profit=max(prices[idx]+solve(prices,idx+1,1),solve(prices,idx+1,0));
        }
        return dp[idx][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,1);
    }
};

//Tabulation

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i][0]: Maximum profit possible up to day i when you do not own a stock.
        // dp[i][1]: Maximum profit possible up to day i when you own a stock.

        int n = prices.size();
        if (n == 0) return 0;  

        vector<vector<int>> dp(n, vector<int>(2, 0));

        // Base cases
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        // Fill the DP table
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i-1][0], prices[i] + dp[i-1][1]);
            dp[i][1] = max(dp[i-1][1], -prices[i] + dp[i-1][0]);
        }

        return dp[n-1][0];
    }
};

//Space Optimization

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;  // Edge case: empty prices array

        int dp0 = 0;  // dp[i-1][0]
        int dp1 = -prices[0];  // dp[i-1][1]

        for (int i = 1; i < n; ++i) {
            int new_dp0 = max(dp0, prices[i] + dp1);
            int new_dp1 = max(dp1, -prices[i] + dp0);
            dp0 = new_dp0;
            dp1 = new_dp1;
        }

        return dp0;
    }
};
