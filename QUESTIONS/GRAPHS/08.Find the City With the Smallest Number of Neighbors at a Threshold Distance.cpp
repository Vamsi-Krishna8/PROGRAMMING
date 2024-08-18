// DIJKSTRAS

class Solution {
public:
  vector<int> dijkstra(int n, int src, vector<pair<int, int>> adj[],
                       int threshold) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
      auto x = pq.top();
      pq.pop();
      int d = x.first;
      int node = x.second;
      if (d > dist[node])
        continue;
      for (auto x : adj[node]) {
        int nbr = x.first;
        int wt = x.second;
        if (dist[nbr] > d + wt) {
          dist[nbr] = d + wt;
          pq.push({dist[nbr], nbr});
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (dist[i] > threshold)
        dist[i] = INT_MAX;
    }

    return dist;
  }
  int findTheCity(int n, vector<vector<int>> &edges, int threshold) {
    int mini = INT_MAX;
    int ans = 0;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < edges.size(); i++) {
      int u = edges[i][0];
      int v = edges[i][1];
      int wt = edges[i][2];
      adj[u].push_back({v, wt});
      adj[v].push_back({u, wt});
    }
    for (int i = 0; i < n; i++) {
      vector<int> temp = dijkstra(n, i, adj, threshold);
      int count = 0;
      for (int i = 0; i < temp.size(); i++) {
        if (temp[i] != INT_MAX) {
          count++;
        }
      }
      if (count <= mini) {
        mini = count;
        ans = i;
      }
      temp.clear();
    }
    return ans;
  }
};

// BELLMAN FORD

class Solution {
public:
  vector<int> bellmanFord(int n, int src, vector<pair<int, int>> adj[],
                          int threshold) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++) {
      for (int u = 0; u < n; u++) {
        for (auto edge : adj[u]) {
          int v = edge.first;
          int weight = edge.second;
          if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            dist[v] = dist[u] + weight;
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (dist[i] > threshold)
        dist[i] = INT_MAX;
    }

    return dist;
  }
  int findTheCity(int n, vector<vector<int>> &edges, int threshold) {
    int mini = INT_MAX;
    int ans = 0;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < edges.size(); i++) {
      int u = edges[i][0];
      int v = edges[i][1];
      int wt = edges[i][2];
      adj[u].push_back({v, wt});
      adj[v].push_back({u, wt});
    }
    for (int i = 0; i < n; i++) {
      vector<int> temp = bellmanFord(n, i, adj, threshold);
      int count = 0;
      for (int i = 0; i < temp.size(); i++) {
        if (temp[i] != INT_MAX) {
          count++;
        }
      }
      if (count <= mini) {
        mini = count;
        ans = i;
      }
    }
    return ans;
  }
};

// FLOYD WARSHAL

class Solution {
public:
  vector<vector<int>> floydWarshall(int n, vector<pair<int, int>> adj[],
                                    int threshold) {
    // Initialize the distance matrix
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++) {
      dist[i][i] = 0;
      for (auto edge : adj[i]) {
        int v = edge.first;
        int wt = edge.second;
        dist[i][v] = wt;
      }
    }
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
              dist[i][k] + dist[k][j] < dist[i][j]) {
            dist[i][j] = dist[i][k] + dist[k][j];
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dist[i][j] > threshold) {
          dist[i][j] = INT_MAX;
        }
      }
    }

    return dist;
  }

  int findTheCity(int n, vector<vector<int>> &edges, int threshold) {
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < edges.size(); i++) {
      int u = edges[i][0];
      int v = edges[i][1];
      int wt = edges[i][2];
      adj[u].push_back({v, wt});
      adj[v].push_back({u, wt});
    }

    vector<vector<int>> dist = floydWarshall(n, adj, threshold);

    int mini = INT_MAX;
    int ans = 0;

    for (int i = 0; i < n; i++) {
      int count = 0;
      for (int j = 0; j < n; j++) {
        if (dist[i][j] != INT_MAX) {
          count++;
        }
      }
      if (count <= mini) {
        mini = count;
        ans = i;
      }
    }

    return ans;
  }
};


