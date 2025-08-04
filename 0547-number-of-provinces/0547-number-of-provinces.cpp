class Solution {
public:
     void solve(int i ,vector<vector<int>>&v,vector<int>&vis){
        vis[i]=1;
        for(auto it : v[i]){
            if(vis[it]==0){
            solve(it,v,vis);
            }
        }
     }
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n=isConnected.size();
       vector<int>vis(n,0);
       vector<vector<int>>v(n);
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
        if(vis[i]==0){
            cnt++;
            solve(i,v,vis);
        }
       }

return cnt;
    }
};