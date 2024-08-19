
class Solution {
public:
  vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
    int n = quiet.size();
    vector<int> adj[n];
    vector<int> inDegree(n, 0);
    vector<int> answer(n);
    for (const auto &edge : richer) {
      int u = edge[0];
      int v = edge[1];
      adj[u].push_back(v);
      inDegree[v]++;
    }
    for (int i = 0; i < n; ++i) {
      answer[i] = i;
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (inDegree[i] == 0) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : adj[u]) {
        if (quiet[answer[u]] < quiet[answer[v]]) {
          answer[v] = answer[u];
        }
        if (--inDegree[v] == 0) {
          q.push(v);
        }
      }
    }
    return answer;
  }
};
