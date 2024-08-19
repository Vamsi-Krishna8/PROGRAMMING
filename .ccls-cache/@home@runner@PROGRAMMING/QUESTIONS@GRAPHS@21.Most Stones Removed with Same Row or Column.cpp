class Solution {
public:
  void dfs(vector<vector<int>> &stones, int idx, vector<int> &vis) {
    vis[idx] = 1;
    for (int i = 0; i < stones.size(); i++) {
      if (i != idx && !vis[i] &&
          (stones[i][0] == stones[idx][0] || stones[i][1] == stones[idx][1])) {
        dfs(stones, i, vis);
      }
    }
  }
  int removeStones(vector<vector<int>> &stones) {
    int n = stones.size();
    int count = 0;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        dfs(stones, i, vis);
        count++;
      }
    }
    return n - count;
  }
};