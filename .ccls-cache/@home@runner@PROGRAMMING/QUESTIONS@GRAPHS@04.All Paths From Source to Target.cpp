class Solution {
public:
  void dfs(vector<vector<int>> &graph, int src, int target,
           vector<vector<int>> &res, vector<int> temp) {
    temp.push_back(src);
    if (src == target) {
      res.push_back(temp);
    } else {
      for (auto &node : graph[src]) {
        dfs(graph, node, target, res, temp);
      }
    }
    temp.pop_back();
  }
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    int n = graph.size();
    int src = 0, target = n - 1;
    vector<int> temp;
    vector<vector<int>> res;
    dfs(graph, src, target, res, temp);
    return res;
  }
};