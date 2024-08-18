class Solution {
public:
  void dfs(unordered_map<string, vector<pair<string, double>>> &adj, string src,
           string dest, unordered_set<string> &vis, double product,
           double &ans) {
    if (vis.find(src) != vis.end())
      return;
    vis.insert(src);
    if (src == dest) {
      ans = product;
      return;
    }
    for (auto &it : adj[src]) {
      string p = it.first;
      double val = it.second;
      dfs(adj, p, dest, vis, product * val, ans);
    }
  }
  vector<double> calcEquation(vector<vector<string>> &equations,
                              vector<double> &values,
                              vector<vector<string>> &queries) {
    int n = equations.size();
    unordered_map<string, vector<pair<string, double>>> adj;
    for (int i = 0; i < n; i++) {
      string u = equations[i][0];
      string v = equations[i][1];
      double val = values[i];
      adj[u].push_back({v, val});
      adj[v].push_back({u, 1.0 / val});
    }
    vector<double> res;
    for (auto &x : queries) {
      string src = x[0];
      string dest = x[1];
      double ans = -1.0;
      double product = 1;
      if (adj.find(src) != adj.end()) {
        unordered_set<string> vis;
        dfs(adj, src, dest, vis, product, ans);
      }
      res.push_back(ans);
    }
    return res;
  }
};