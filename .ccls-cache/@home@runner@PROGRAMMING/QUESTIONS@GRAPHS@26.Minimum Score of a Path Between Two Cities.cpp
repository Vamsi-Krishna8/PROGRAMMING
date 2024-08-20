// DFS

class Solution {
public:
  int mini = INT_MAX;

  void dfs(int curr, vector<vector<pair<int, int>>> &adj, vector<int> &vis) {
    vis[curr] = 1;
    for (auto it : adj[curr]) {
      int node = it.first;
      int cost = it.second;
      mini = min(mini, cost);
      if (!vis[node]) {
        dfs(node, adj, vis);
      }
    }
  }
  int minScore(int n, vector<vector<int>> &roads) {
    vector<vector<pair<int, int>>> adj(n);
    for (auto x : roads) {
      int src = x[0] - 1;
      int dest = x[1] - 1;
      int cost = x[2];
      adj[src].push_back({dest, cost});
      adj[dest].push_back({src, cost});
    }
    vector<int> vis(n, 0);
    dfs(0, adj, vis);
    return mini;
  }
};

// BFS

class Solution {
public:
  int mini = INT_MAX;
  int minScore(int n, vector<vector<int>> &roads) {
    vector<vector<pair<int, int>>> adj(n);
    for (auto x : roads) {
      int src = x[0] - 1;
      int dest = x[1] - 1;
      int cost = x[2];
      adj[src].push_back({dest, cost});
      adj[dest].push_back({src, cost});
    }
    queue<int> q;
    vector<int> vis(n, 0);
    q.push(0);
    vis[0] = 1;
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      for (auto it : adj[curr]) {
        int node = it.first;
        int cost = it.second;
        mini = min(mini, cost);
        if (!vis[node]) {
          q.push(node);
          vis[node] = 1;
        }
      }
    }
    return mini;
  }
};