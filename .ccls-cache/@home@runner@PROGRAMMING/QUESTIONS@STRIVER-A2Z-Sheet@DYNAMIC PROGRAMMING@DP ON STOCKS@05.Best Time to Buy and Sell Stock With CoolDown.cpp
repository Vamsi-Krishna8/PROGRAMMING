//Memo

class Solution {
public:
    int dp[5001][2];  // Memoization table

    int solve(vector<int>& prices, int idx, int holding) {
        // Base case: No more days left
        if (idx >= prices.size()) return 0;

        // Check if result is already computed
        if (dp[idx][holding] != -1) return dp[idx][holding];

        // Option 1: Do nothing (stay in the same state)
        int doNothing = solve(prices, idx + 1, holding);

        int doSomething;
        if (holding) {
            // Option 2: Sell the stock, go to cooldown
            doSomething = prices[idx] + solve(prices, idx + 2, 0);
        } else {
            // Option 2: Buy the stock
            doSomething = -prices[idx] + solve(prices, idx + 1, 1);
        }

        // Maximize profit by choosing the best option
        return dp[idx][holding] = max(doNothing, doSomething);
    }

    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));  // Initialize memoization table with -1
        return solve(prices, 0, 0);  // Start at day 0 without holding a stock
    }
};

//Tabulation

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        // Initialize the DP array
        vector<int> dp(n, 0);

        // Base cases
        dp[0] = 0;  // No profit on the first day
        if (n > 1) {
            dp[1] = max(0, prices[1] - prices[0]);  // Max profit from buying on day 0 and selling on day 1
        }

        // Fill the DP array
        for (int i = 2; i < n; ++i) {
            dp[i] = dp[i-1];  // Assume a cooldown day (no transaction)

            // Check all possible buy days before day i
            for (int j = 0; j <= i - 1; ++j) {
                int prev_profit = j >= 2 ? dp[j-2] : 0;  // Get profit from day before the buy day, with cooldown
                dp[i] = max(dp[i], prices[i] - prices[j] + prev_profit);  // Update the max profit for day i
            }
        }

        // The last element in dp array gives the maximum profit
        return dp[n-1];
    }
};

