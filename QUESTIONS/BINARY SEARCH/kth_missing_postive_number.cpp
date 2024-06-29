// O(n) approach
class Solution {
public:
  int findKthPositive(vector<int> &arr, int k) {
    int i = 0;
    int n = arr.size();
    int num = 1;
    while (i < n && k > 0) {
      if (num == arr[i])
        i++;
      else {
        k--;
      }
      num++;
    }
    while (k--)
      num++;
    return num - 1;
  }
};

// O(logn) approach

class Solution {
public:
  int findKthPositive(vector<int> &arr, int k) {
    int n = arr.size();
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      int missing_till_mid = arr[mid] - (mid + 1);
      if (missing_till_mid < k) {
        lo = mid + 1;
      } else
        hi = mid - 1;
    }
    return lo + k;
  }
};