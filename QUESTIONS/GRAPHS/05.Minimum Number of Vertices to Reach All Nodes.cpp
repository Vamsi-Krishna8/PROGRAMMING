class Solution {
public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges) {
    vector<int> indegree(n);
    for (auto &x : edges) {
      indegree[x[1]]++;
    }
    vector<int> res;
    for (int i = 0; i < n; i++) {
      if (indegree[i] == 0) {
        res.push_back(i);
      }
    }
    return res;
  }
};