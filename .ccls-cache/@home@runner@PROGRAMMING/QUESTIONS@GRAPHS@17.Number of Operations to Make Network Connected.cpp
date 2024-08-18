class Solution {
public:
  vector<int> parent;
  vector<int> rank;

  int find(int x) {
    if (x == parent[x]) {
      return x;
    }
    return parent[x] = find(parent[x]);
  }

  void Union(int x, int y) {
    int x_par = find(x);
    int y_par = find(y);
    if (x_par == y_par)
      return;
    if (rank[x_par] > rank[y_par]) {
      parent[y_par] = x_par;
    } else if (rank[x_par] < rank[y_par]) {
      parent[x_par] = y_par;
    } else {
      parent[x_par] = y_par;
      rank[y_par]++;
    }
  }
  int makeConnected(int n, vector<vector<int>> &connections) {
    if (connections.size() < n - 1)
      return -1;
    parent.resize(n, 0);
    rank.resize(n, 0);
    for (int i = 0; i < n; i++)
      parent[i] = i;
    int components = n;
    for (int i = 0; i < connections.size(); i++) {
      int u = connections[i][0];
      int v = connections[i][1];
      if (find(u) != find(v)) {
        Union(u, v);
        components--;
      }
    }
    return components - 1;
  }
};