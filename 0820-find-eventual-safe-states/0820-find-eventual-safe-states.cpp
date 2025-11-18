class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj(n);
        vector<int>ind(n,0);
        for(int u=0;u<n;u++){
            for(auto v  : graph[u]){
                ind[u]++;
                adj[v].push_back(u);
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        vector<int>sn;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            sn.push_back(x);
            for(auto it : adj[x]){
                ind[it]--;
                if(ind[it]==0){
                    q.push(it);
                }
            }
        }
        sort(sn.begin(),sn.end());
        return sn;
    }
};