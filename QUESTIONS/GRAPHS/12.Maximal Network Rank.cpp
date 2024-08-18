// Approach 1
class Solution {
public:
  int maximalNetworkRank(int n, vector<vector<int>> &roads) {
    vector<set<int>> adj(n);
    for (auto x : roads) {
      int u = x[0];
      int v = x[1];
      adj[u].insert(v);
      adj[v].insert(u);
    }
    int maxi = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int sum = adj[i].size() + adj[j].size();
        if (adj[i].find(j) != adj[i].end())
          sum--;
        maxi = max(maxi, sum);
      }
    }
    return maxi;
  }
};

// Approach 2

class Solution {
public:
  int maximalNetworkRank(int n, vector<vector<int>> &roads) {
    vector<int> degree(n);
    vector<vector<bool>> connected(n, vector<bool>(n, false));

    for (auto &road : roads) {
      int u = road[0];
      int v = road[1];
      degree[u]++;
      degree[v]++;
      connected[u][v] = true;
      connected[v][u] = true;
    }
    int maxi = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int sum = degree[i] + degree[j];

        if (connected[i][j] || connected[j][i]) {
          sum--;
        }
        maxi = max(maxi, sum);
      }
    }

    return maxi;
  }
};
