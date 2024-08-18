// Approach 1 (with visited array)
class Solution {
public:
  int dfs(int curr, vector<int> adj[], vector<int> &vis) {
    int count = 0;
    vis[curr] = 1;
    for (auto x : adj[curr]) {
      if (!vis[abs(x)]) {
        count += dfs(abs(x), adj, vis) + (x > 0);
      }
    }
    return count;
  }

  int minReorder(int n, vector<vector<int>> &connections) {
    vector<int> adj[n];
    for (auto &x : connections) {
      int u = x[0];
      int v = x[1];
      // u -> v (Original direction)
      adj[u].push_back(v);
      adj[v].push_back(-u);
    }
    vector<int> vis(n, 0);
    return dfs(0, adj, vis);
  }
};

// Approach 2 (without using visited array)

class Solution {
public:
  int dfs(int curr, int parent, vector<int> adj[]) {
    int count = 0;
    for (auto x : adj[curr]) {
      if (abs(x) != parent) {
        count += dfs(abs(x), curr, adj) + (x > 0);
      }
    }
    return count;
  }
  int minReorder(int n, vector<vector<int>> &connections) {
    vector<int> adj[n];
    for (auto &x : connections) {
      int u = x[0];
      int v = x[1];
      // u -> v (Original direction)
      adj[u].push_back(v);
      adj[v].push_back(-u);
    }
    vector<int> vis(n, 0);
    return dfs(0, -1, adj);
  }
};
