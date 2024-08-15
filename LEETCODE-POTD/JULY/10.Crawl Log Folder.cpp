class Solution {
public:
  int minOperations(vector<string> &logs) {
    int d = 0;
    for (auto x : logs) {
      if (x == "../") {
        d = max(0, d - 1);
      } else if (x != "./")
        d++;
    }
    return d;
  }
};