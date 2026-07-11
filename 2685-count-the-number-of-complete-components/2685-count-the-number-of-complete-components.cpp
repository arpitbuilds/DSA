class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<int>& vis, int &nodes,
             int &degsum) {
        vis[i] = 1;
        degsum += adj[i].size();
        nodes++;
        for (auto it : adj[i]) {
            if (!vis[it]) {
                dfs(it, adj, vis, nodes, degsum);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int nodes = 0;
                int degsum = 0;
                dfs(i, adj, vis, nodes, degsum);
                int edge = degsum / 2;
                if (edge == (nodes * (nodes - 1)) / 2) {
                    ans++;
                }
            }
        }
        return ans;
    }
};