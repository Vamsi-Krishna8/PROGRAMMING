class Solution {
public:
  void dfs(vector<vector<int>> &rooms, vector<int> &vis, int node) {
    vis[node] = 1;
    for (auto x : rooms[node]) {
      if (!vis[x]) {
        dfs(rooms, vis, x);
      }
    }
  }
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    vector<int> vis(rooms.size(), 0);
    dfs(rooms, vis, 0);
    for (auto x : vis) {
      if (x == 0)
        return false;
    }
    return true;
  }
};