// DFS

class Solution {
public:
  int count = 1;
  void dfs(int curr, int par, vector<int> adj[], vector<int> &seen) {
    for (auto it : adj[curr]) {
      if (it != par && seen[it] != 1) {
        count++;
        dfs(it, curr, adj, seen);
      }
    }
  }
  int reachableNodes(int n, vector<vector<int>> &edges,
                     vector<int> &restricted) {
    vector<int> adj[n];
    for (auto x : edges) {
      int u = x[0];
      int v = x[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<int> seen(n);
    for (auto x : restricted) {
      seen[x] = 1;
    }
    dfs(0, -1, adj, seen);
    return count;
  }
};

// BFS

class Solution {
public:
  int reachableNodes(int n, vector<vector<int>> &edges,
                     vector<int> &restricted) {
    vector<int> adj[n];
    for (auto x : edges) {
      int u = x[0];
      int v = x[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<int> seen(n, 0);
    for (auto x : restricted) {
      seen[x] = 1;
    }
    queue<int> q;
    q.push(0);
    seen[0] = 1;
    int count = 1;
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      for (auto it : adj[curr]) {
        if (!seen[it]) {
          q.push(it);
          seen[it] = 1;
          count++;
        }
      }
    }
    return count;
  }
};