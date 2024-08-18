bool dfs(vector<int> adj[], int curr, vector<int> &vis,
         vector<int> &inRecursion) {
  vis[curr] = 1;
  inRecursion[curr] = 1;

  for (auto it : adj[curr]) {
    if (!vis[it]) {
      if (dfs(adj, it, vis, inRecursion)) {
        return true; // Cycle detected in the recursive call
      }
    } else if (inRecursion[it] == 1) {
      return true; // Cycle detected
    }
  }

  inRecursion[curr] = 0; // Remove the node from the recursion stack
  return false;          // No cycle detected in this branch
}

bool isCyclic(int v, vector<int> adj[]) {
  vector<int> vis(v, 0);
  vector<int> inRecursion(v, 0);

  for (int i = 0; i < v; i++) {
    if (!vis[i]) {
      if (dfs(adj, i, vis, inRecursion)) {
        return true; // If any component has a cycle, return true
      }
    }
  }

  return false; // No cycle found in any component
}