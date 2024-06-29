#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool check(int mid, vector<int> &v, int k) {
  int n = v.size();
  int count = 1;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] > mid)
      return false;
    if (sum + v[i] <= mid) {
      sum += v[i];
    } else {
      count++;
      sum = v[i];
    }
  }
  return count <= k;
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  int lo = 1, hi = 1e15, ans = -1;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (check(mid, v, k)) {
      ans = mid;
      hi = mid - 1;
    } else
      lo = mid + 1;
  }
  cout << ans << endl;
}
int32_t main() {
  int t;
  t = 1;
  // cin>>t;
  while (t--) {

    // cout<<t;
    solve();
  }
  return 0;
}