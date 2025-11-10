class Solution {
  public:
    void bfs(int i,  vector<vector<int>>&adj,vector<int>&vis,vector<int>&temp){
        vis[i]=true;
        queue<int>q;
        q.push(i);
        while(!q.empty()){
            int top=q.front();
            q.pop();
            temp.push_back(top);
            for(auto it : adj[top]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
            
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(V,0);
        vector<vector<int>>ans;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                vector<int>temp;
                bfs(i,adj,vis,temp);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
