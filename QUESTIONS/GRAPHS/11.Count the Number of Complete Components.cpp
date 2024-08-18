class Solution {
public:
    void dfs(int curr, vector<int> adj[], vector<int>& vis, int& nodeCount, int& edgeCount)  
    {
        vis[curr] = 1;
        nodeCount++;
        edgeCount += adj[curr].size();

        for (auto x : adj[curr]) {
            if (!vis[x]) {
                dfs(x,adj,vis,nodeCount,edgeCount);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        int count = 0;
        for (auto x : edges) {
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int nodeCount = 0;
                int edgeCount = 0;
                dfs(i, adj, vis, nodeCount, edgeCount);
                if (edgeCount == nodeCount * (nodeCount - 1)) {
                    count++;
                }
            }
        }
        return count;
    }
};
