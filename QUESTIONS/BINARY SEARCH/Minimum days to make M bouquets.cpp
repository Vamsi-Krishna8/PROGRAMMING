class Solution {
public:
  bool check(int mid, int m, int k, vector<int> &nums) {
    int count = 0;
    int n = nums.size();
    int group = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] <= mid)
        count++;
      else
        count = 0;
      if (count == k) {
        group++;
        count = 0;
      }
    }
    return group >= m;
  }
  int minDays(vector<int> &nums, int m, int k) {
    int n = nums.size();
    int lo = 1, hi = *max_element(nums.begin(), nums.end());
    if (n < (long long)m * k)
      return -1;
    int ans = 0;
    long long req = m * k;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (check(mid, m, k, nums)) {
        ans = mid;
        hi = mid - 1;
      } else
        lo = mid + 1;
    }
    return ans;
  }
};