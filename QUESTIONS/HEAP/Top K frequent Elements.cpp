class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    map<int, int> mp;
    for (auto x : nums)
      mp[x]++;
    priority_queue<pair<int, int>> pq;
    for (auto x : mp) {
      pq.push({x.second, x.first});
    }
    vector<int> ans;
    while (k--) {
      auto y = pq.top();
      pq.pop();
      ans.push_back(y.second);
    }
    return ans;
  }
