/*
  Approach 1 (Check if there is a path between two nodes before adding a new
  edge because if there exists a path between them then adding that edge will
  result in creation of cycle which results it as a redundant edge.
*/

class Solution {
public:
  bool dfs(vector<vector<int>> &graph, vector<int> &vis, int u, int v) {
    if (u == v)
      return true;
    vis[u] = 1;
    for (auto it : graph[u]) {
      if (!vis[it]) {
        if (dfs(graph, vis, it, v))
          return true;
      }
    }
    return false;
  }
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int n = edges.size();
    vector<vector<int>> graph(n + 1);
    vector<int> vis(n + 1);
    for (auto &x : edges) {
      fill(begin(vis), end(vis), false);
      int u = x[0];
      int v = x[1];
      if (dfs(graph, vis, u, v))
        return {u, v};
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    return {};
  }
};

/*
  Approach 2(Check whether there is a cycle formation after adding the edge u->v
  if there is cycle formation after adding that edge then that edge will be
  redundant edge
*/

class Solution {
public:
  bool dfs(vector<vector<int>> &graph, vector<int> &vis, int u, int par) {
    vis[u] = 1;
    for (auto it : graph[u]) {
      if (!vis[it]) {
        if (dfs(graph, vis, it, u))
          return true;
      } else if (it != par) {
        return true;
      }
    }
    return false;
  }
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int n = edges.size();
    vector<vector<int>> graph(n + 1);
    vector<int> vis(n + 1);
    for (auto &x : edges) {
      fill(begin(vis), end(vis), false);
      int u = x[0];
      int v = x[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
      if (dfs(graph, vis, u, -1))
        return {u, v};
    }
    return {};
  }
};

/*
  Approach 3(Kahn's Algorithm)) for the nodes with greater than 1 indegree then
  that node is a part of the cycle so we are finding the last edge which is
  contributing to the cycle
*/

class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int n = edges.size();
    vector<int> indegree(n + 1, 0);
    vector<vector<int>> graph(n + 1);
    for (auto &x : edges) {
      indegree[x[0]]++;
      indegree[x[1]]++;
      graph[x[0]].push_back(x[1]);
      graph[x[1]].push_back(x[0]);
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
      if (indegree[i] == 1) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      for (auto &x : graph[curr]) {
        indegree[x]--;
        if (indegree[x] == 1) {
          q.push(x);
        }
      }
    }
    vector<int> res;
    for (auto x : edges) {
      if (indegree[x[0]] > 1 && indegree[x[1]] > 1) {
        res = {x[0], x[1]};
      }
    }

    return res;
  }
};