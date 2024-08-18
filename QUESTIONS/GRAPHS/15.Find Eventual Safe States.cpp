// DFS

class Solution {
public:
  bool dfs(vector<vector<int>> &graph, int curr, vector<int> &vis,
           vector<int> &inRecursion) {
    vis[curr] = 1;
    inRecursion[curr] = 1;
    for (auto it : graph[curr]) {
      if (!vis[it]) {
        if (dfs(graph, it, vis, inRecursion))
          return true;
      } else if (inRecursion[it] == true)
        return true;
    }
    inRecursion[curr] = 0;
    return false;
  }
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> vis(n, 0);
    vector<int> inRecursion(n, 0);
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        dfs(graph, i, vis, inRecursion);
      }
    }
    vector<int> safeNodes;
    for (int i = 0; i < n; i++) {
      if (inRecursion[i] == 0)
        safeNodes.push_back(i);
    }
    return safeNodes;
  }
};

// BFS

class Solution {
public:
  vector<int> topoSort(int V, vector<int> adj[]) {
    // code here
    vector<int> indegree(V, 0);
    queue<int> q;
    for (int i = 0; i < V; i++) {
      for (auto x : adj[i]) {
        indegree[x]++;
      }
    }
    for (int i = 0; i < V; i++) {
      if (indegree[i] == 0)
        q.push(i);
    }
    vector<int> res(V);
    while (!q.empty()) {
      int node = q.front();
      res[node] = 1;
      q.pop();
      for (auto x : adj[node]) {
        indegree[x]--;
        if (indegree[x] == 0) {
          q.push(x);
        }
      }
    }
    return res;
  }
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> adj[n];
    for (int i = 0; i < n; i++) {
      for (auto x : graph[i]) {
        adj[x].push_back(i);
      }
    }
    vector<int> res = topoSort(n, adj);
    vector<int> safeNodes;
    for (int i = 0; i < n; i++) {
      if (res[i] != 0)
        safeNodes.push_back(i);
    }
    return safeNodes;
  }
};