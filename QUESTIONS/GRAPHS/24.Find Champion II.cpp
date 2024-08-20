class Solution {
public:
  int findChampion(int n, vector<vector<int>> &edges) {
    if (edges.size() == 0 && n > 1)
      return -1;
    vector<int> indegree(n, 0);
    for (auto x : edges) {
      indegree[x[1]]++;
    }
    int count = 0;
    int ans = -1;
    for (int i = 0; i < n; i++) {
      if (indegree[i] == 0) {
        ans = i;
        count++;
      }
      if (count > 1)
        return -1;
    }
    return ans;
  }
};