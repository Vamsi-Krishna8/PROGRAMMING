class Solution {
public:
  int prims(int src, vector<pair<int, int>> adj[], vector<int> &inMST) {
    int sum = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, src});
    while (!pq.empty()) {
      auto x = pq.top();
      pq.pop();
      int dist = x.first;
      int node = x.second;
      if (inMST[node] == 1)
        continue;
      inMST[node] = 1;
      sum += dist;

      for (auto x : adj[node]) {
        int neighbor = x.first;
        int wt = x.second;
        if (inMST[neighbor] == 0) {
          pq.push({wt, neighbor});
        }
      }
    }
    return sum;
  }
  int minCostConnectPoints(vector<vector<int>> &points) {
    int n = points.size();
    vector<pair<int, int>> adj[n];
    for (int u = 0; u < n; u++) {
      for (int v = u + 1; v < n; v++) {
        int ux = points[u][0];
        int uy = points[u][1];
        int vx = points[v][0];
        int vy = points[v][1];
        int dist = abs(ux - vx) + abs(uy - vy);
        adj[u].push_back({v, dist});
        adj[v].push_back({u, dist});
      }
    }
    vector<int> inMST(n, 0);
    return prims(0, adj, inMST);
  }
};