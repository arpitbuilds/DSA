class Solution {
public:
    int solve(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&vis){
         int m=grid.size();
        int n=grid[0].size();
        vis[r][c]=1;
        int ans=1;
        int delr[]={0,-1,0,1};
        int delc[]={-1,0,1,0};
        for(int k=0;k<4;k++){
            int nr=r+delr[k];
            int nc=c+delc[k];
            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1 && !vis[nr][nc]){
                ans+=solve(nr,nc,grid,vis);
            }
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                   int ans=solve(i,j,grid,vis);
                    maxi=max(maxi,ans);
                }
            }
        }
        return maxi;
    }
};