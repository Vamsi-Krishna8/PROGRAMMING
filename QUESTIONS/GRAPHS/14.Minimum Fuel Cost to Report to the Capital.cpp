class Solution {
public:
  long long ans = 0;
  long long dfs(int curr, vector<int> adj[], int seats, vector<int> &vis) {
    long long count = 0;
    vis[curr] = 1;
    for (auto it : adj[curr]) {
      if (!vis[it]) {
        count += dfs(it, adj, seats, vis);
      }
    }
    count += 1;
    if (curr != 0) {
      ans += (count + seats - 1) / seats;
    }
    return count;
  }

  long long minimumFuelCost(vector<vector<int>> &roads, int seats) {
    int n = roads.size() + 1;
    vector<int> adj[n];
    for (auto x : roads) {
      int u = x[0];
      int v = x[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<int> vis(n, 0);
    dfs(0, adj, seats, vis);
    return ans;
  }
};
