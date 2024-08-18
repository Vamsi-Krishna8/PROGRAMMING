
class Solution {
public:
  // Function to detect cycle in a directed graph.
  bool isCyclic(int V, vector<int> adj[]) {
    // code here
    vector<int> indegree(V, 0);
    queue<int> q;
    for (int i = 0; i < V; i++) {
      for (auto x : adj[i]) {
        indegree[x]++;
      }
    }
    int count = 0;
    for (int i = 0; i < V; i++) {
      if (indegree[i] == 0) {
        q.push(i);
        count++;
      }
    }
    vector<int> res;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      for (auto x : adj[node]) {
        indegree[x]--;
        if (indegree[x] == 0) {
          q.push(x);
          count++;
        }
      }
    }
    if (count == V)
      return false;
    return true;
  }
};
