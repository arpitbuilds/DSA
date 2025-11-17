class Solution {
public:
     void dfs(int s,vector<int>&vis,vector<vector<int>>&v){
        vis[s]=1;
        for(auto it : v[s]){
            if(!vis[it]){
                dfs(it,vis,v);
            }
        }
     }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>v(n);
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                  cnt++;
                dfs(i,vis,v);
            }
        }
        return cnt;
    }
};