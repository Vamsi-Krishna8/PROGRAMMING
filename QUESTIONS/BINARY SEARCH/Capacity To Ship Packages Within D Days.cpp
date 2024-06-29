class Solution {
public:
  bool check(int mid, vector<int> &weights, int days) {
    int count = 1;
    int total = 0;
    for (int i = 0; i < weights.size(); i++) {
      if (weights[i] > mid)
        return false;
      if (weights[i] + total <= mid) {
        total += weights[i];
      } else {
        count++;
        total = weights[i];
      }
    }
    return count <= days;
  }
  int shipWithinDays(vector<int> &weights, int days) {
    int lo = 1, hi = 1e9, ans = -1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (check(mid, weights, days)) {
        ans = mid;
        hi = mid - 1;
      } else
        lo = mid + 1;
    }
    return ans;
  }
};