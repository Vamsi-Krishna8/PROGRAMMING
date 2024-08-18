class Solution {
public:
  long long maximumImportance(int n, vector<vector<int>> &roads) {
    long long answer = 0;
    vector<int> indegree(n, 0);

    for (auto &x : roads) {
      indegree[x[0]]++;
      indegree[x[1]]++;
    }
    sort(indegree.begin(), indegree.end());
    for (int i = 0; i < n; i++) {
      answer += (long long)(indegree[i]) * (i + 1);
    }

    return answer;
  }
};
