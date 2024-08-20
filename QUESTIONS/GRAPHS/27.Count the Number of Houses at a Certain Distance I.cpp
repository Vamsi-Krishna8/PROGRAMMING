class Solution {
public:
  vector<int> countOfPairs(int n, int x, int y) {
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 1000));
    for (int i = 1; i < n; i++) {
      adj[i][i + 1] = 1;
      adj[i + 1][i] = 1;
    }
    adj[x][y] = 1;
    adj[y][x] = 1;

    for (int via = 1; via <= n; via++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
        }
      }
    }
    vector<int> res(n);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i != j) {
          int val = adj[i][j];
          res[val - 1]++;
        }
      }
    }
    return res;
  }
};