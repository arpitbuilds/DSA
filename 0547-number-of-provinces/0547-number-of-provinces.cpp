class Solution {
public:
     void solve(int i,vector<int>&vis,vector<vector<int>>&v){
        vis[i]=1;
        for(auto it : v[i]){
            if(!vis[it]){
                solve(it,vis,v);

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
            solve(i,vis,v);
        }
       }
       return cnt;
    }
};