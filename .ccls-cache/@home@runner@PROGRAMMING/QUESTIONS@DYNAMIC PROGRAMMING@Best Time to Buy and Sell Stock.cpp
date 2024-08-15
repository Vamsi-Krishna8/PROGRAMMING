class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    int mini = prices[0];
    int res = 0;
    for (int i = 0; i < n; i++) {
      res = max(res, prices[i] - mini);
      mini = min(mini, prices[i]);
    }
    return res;
  }
};