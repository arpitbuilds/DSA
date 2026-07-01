class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& p) {
        vector<vector<int>> adj(num);
        for (auto it : p) {
            adj[it[1]].push_back(it[0]);
        }
        vector<int> ind(num, 0);
        for (int i = 0; i < num; i++) {
            for (auto it : adj[i]) {
                ind[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < num; i++) {
            if (ind[i] == 0) {
                q.push(i);
            }
        }
        vector<int> v;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            v.push_back(x);
            for (auto it : adj[x]) {
                ind[it]--;
                if (ind[it] == 0) {
                    q.push(it);
                }
            }
        }
        return v.size()==num;
    }
};