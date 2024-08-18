// Approach 1 (using map)

class Solution {
public:
  int findCenter(vector<vector<int>> &edges) {
    int n = edges.size();
    unordered_map<int, int> degree;

    for (auto &vec : edges) {
      int u = vec[0];
      int v = vec[1];

      degree[u]++;
      degree[v]++;
    }

    for (auto &it : degree) {
      int node = it.first;
      int deg = it.second;

      if (deg == n)
        return node;
    }

    return -1;
  }
};

// Approach 2

class Solution {
public:
  int findCenter(vector<vector<int>> &edges) {
    vector<int> first = edges[0];  //{a, b}
    vector<int> second = edges[1]; //{c, a}

    if (first[0] == second[0] || first[0] == second[1]) {
      return first[0];
    }

    return first[1];
  }
};