class Solution {
private:
  void dfs(int node, vector<int> &vis, vector<int> adjls[]) {
    vis[node] = 1;
    for (auto it : adjls[node]) {
      if (!vis[it]) {
        dfs(it, vis, adjls);
      }
    }
  }

public:
  int findCircleNum(vector<vector<int>> &adj) {
    int n = adj.size();
    vector<int> adjls[n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (adj[i][j] == 1 && i != j) {
          adjls[i].push_back(j);
          adjls[j].push_back(i);
        }
      }
    }
    vector<int> vis(n, 0);
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        count++;
        dfs(i, vis, adjls);
      }
    }
    return count;
  }
};