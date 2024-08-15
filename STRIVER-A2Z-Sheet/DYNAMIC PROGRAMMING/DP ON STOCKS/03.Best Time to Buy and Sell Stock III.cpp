//Memo

class Solution {
public:
    int dp[100001][3][2];  

    int solve(vector<int>& prices, int idx, int transactionsLeft, int buy) {
        if (idx >= prices.size() || transactionsLeft == 0) return 0;
        if (dp[idx][transactionsLeft][buy] != -1) return dp[idx][transactionsLeft][buy];

        if (buy) {
            int doNothing = solve(prices, idx + 1, transactionsLeft, 1);
            int buy = -prices[idx] + solve(prices, idx + 1, transactionsLeft, 0);
            dp[idx][transactionsLeft][1] = max(doNothing, buy);
        } 
        else {
            int doNothing = solve(prices, idx + 1, transactionsLeft, 0);
            int sell = prices[idx] + solve(prices, idx + 1, transactionsLeft - 1, 1);
            dp[idx][transactionsLeft][0] = max(doNothing, sell);
        }
        return dp[idx][transactionsLeft][buy];
    }

    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));  
        return solve(prices, 0, 2, 1);
    }
};

//Tabulation

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //dp[i][k][0]: Maximum profit on day i with k transactions and not holding any stock.
        //dp[i][k][1]: Maximum profit on day i with k transactions and holding a stock.
        int n = prices.size();
        if (n == 0) return 0;
        int dp[n][3][2];  // dp[i][k][0] and dp[i][k][1]
        memset(dp,0,sizeof(dp));

        // Base cases:
        dp[0][0][0] = 0;          // No transactions, no stock, no profit
        dp[0][0][1] = -prices[0]; // No transactions, holding stock on day 0 is just a negative purchase price

        // Similarly, for one and two transactions
        for (int k = 1; k <= 2; ++k) {
            dp[0][k][0] = 0;          // No stock, no profit
            dp[0][k][1] = -prices[0];  // Bought stock on the first day
        }

        for (int i = 1; i < n; ++i) {
            for (int k = 1; k <= 2; ++k) {
                // Transition for not holding a stock
                dp[i][k][0] = max(dp[i-1][k][0], prices[i] + dp[i-1][k][1]);

                // Transition for holding a stock
                dp[i][k][1] = max(dp[i-1][k][1], -prices[i] + dp[i-1][k-1][0]);
            }
        }

        // The maximum profit with at most 2 transactions without holding any stock at the end
        return dp[n-1][2][0];
    }
};

