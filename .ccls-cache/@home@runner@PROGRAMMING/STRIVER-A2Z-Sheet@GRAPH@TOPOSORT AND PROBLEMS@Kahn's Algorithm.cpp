
class Solution {
public:
  // Function to return list containing vertices in Topological order.
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
    vector<int> res;
    while (!q.empty()) {
      int node = q.front();
      res.push_back(node);
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
};