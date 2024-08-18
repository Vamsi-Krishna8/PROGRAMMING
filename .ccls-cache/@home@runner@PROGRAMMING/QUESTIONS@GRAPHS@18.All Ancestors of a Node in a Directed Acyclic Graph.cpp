// Approach 1

class Solution {
public:
  vector<vector<int>> result;
  void dfs(int curr, vector<int> adj[], int ancestor) {
    for (int &it : adj[curr]) {
      if (result[it].empty() || result[it].back() != ancestor) {
        result[it].push_back(ancestor);
        dfs(it, adj, ancestor);
      }
    }
  }

  vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
    result.resize(n);
    vector<int> adj[n];
    for (auto x : edges) {
      int u = x[0];
      int v = x[1];
      adj[u].push_back(v); // u-->v
    }
    for (int i = 0; i < n; i++) {
      int ancestor = i;
      dfs(i, adj, ancestor);
    }
    return result;
  }
};

// Approach 2

class Solution {
public:
  vector<vector<int>> result;
  void dfs(int curr, vector<int> adj[], vector<int> &vis) {
    vis[curr] = 1;
    for (auto it : adj[curr]) {
      if (!vis[it])
        dfs(it, adj, vis);
    }
  }

  vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
    result.resize(n);
    vector<int> adj[n];
    for (auto x : edges) {
      int u = x[0];
      int v = x[1];
      adj[v].push_back(u); // u-->v
    }
    for (int u = 0; u < n; u++) {
      vector<int> vis(n, 0);
      dfs(u, adj, vis);
      for (int i = 0; i < n; i++) {
        if (vis[i] && i != u)
          result[u].push_back(i);
      }
    }
    return result;
  }
};

// Approach3 (TopoLogical Sort)

class Solution {
public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
    vector<vector<int>> result(n);
    vector<int> adj[n];

    vector<int> indegree(n, 0);

    for (vector<int> &vec : edges) { // O(E)
      int u = vec[0];
      int v = vec[1];
      adj[u].push_back(v); // u --> v
      indegree[v]++;
    }
    // TOPOLOGICAL SORTING
    queue<int> que;
    for (int i = 0; i < n; i++) {
      if (indegree[i] == 0) {
        que.push(i);
      }
    }

    vector<int> topoOrder;
    while (!que.empty()) {
      int curr = que.front();
      que.pop();
      topoOrder.push_back(curr);

      for (int &v : adj[curr]) {
        indegree[v]--;
        if (indegree[v] == 0) {
          que.push(v);
        }
      }
    }

    vector<unordered_set<int>> vec(n);
    for (int &node : topoOrder) {
      for (int &v : adj[node]) {
        vec[v].insert(node); // adding node ancestor
        vec[v].insert(vec[node].begin(),
                      vec[node].end()); // adding ancestors of node
      }
    }
    for (int i = 0; i < n; i++) {
      result[i] = vector<int>(vec[i].begin(), vec[i].end());
      sort(result[i].begin(), result[i].end());
    }
    return result;
  }
};
