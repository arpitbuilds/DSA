class Solution {
public:
    void solve(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&vis){
       int m=grid.size();
        int n=grid[0].size();
        vis[i][j]=1;
        int drow[]={0,-1,0,1};
        int dcol[]={-1,0,1,0};
        for(int k=0;k<4;k++){
            int nrow=i+drow[k];
            int ncol=j+dcol[k];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                solve(nrow,ncol,grid,vis);

            }
        } 
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        vector<vector<int>>v(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !v[i][j]){
                    ans++;
                    solve(i,j,grid,v);
                }
            }
        }
        return ans;
    }
};