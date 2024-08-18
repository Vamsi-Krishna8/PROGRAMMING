// DFS

class Solution {
public:
  bool dfs(vector<int> adj[], int s, int d, vector<int> &vis) {
    if (s == d)
      return true;
    if (vis[s] == 1)
      return false;
    vis[s] = 1;
    for (auto x : adj[s]) {
      if (!vis[x]) {
        if (dfs(adj, x, d, vis))
          return true;
      }
    }
    return false;
  }
  bool validPath(int n, vector<vector<int>> &edges, int source,
                 int destination) {
    vector<int> adj[n];
    for (int i = 0; i < edges.size(); i++) {
      int u = edges[i][0];
      int v = edges[i][1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<int> vis(n, 0);
    return dfs(adj, source, destination, vis);
  }
};

// BFS

class Solution {
public:
  bool validPath(int n, vector<vector<int>> &edges, int source,
                 int destination) {
    vector<int> adj[n];
    for (int i = 0; i < edges.size(); i++) {
      int u = edges[i][0];
      int v = edges[i][1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<int> vis(n, 0);
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      if (node == destination)
        return true;
      for (auto x : adj[node]) {
        if (!vis[x]) {
          q.push(x);
          vis[x] = 1;
        }
      }
    }
    return false;
  }
};