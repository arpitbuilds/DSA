class Solution {
public:
    void dfs(int node, vector<vector<int>>& ls, vector<int>& vis) {
        vis[node] = 1;
        for (auto it : ls[node]) {
            if (!vis[it])
                dfs(it, ls, vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> ls(isConnected.size());
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected.size(); j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    ls[i].push_back(j);
                    ls[j].push_back(i);
                }
            }
        }
        vector<int> vis(isConnected.size(), 0);
        int cnt = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            if ((!vis[i]))
                cnt++;
            dfs(i, ls, vis);
        }
        return cnt;
    }
};