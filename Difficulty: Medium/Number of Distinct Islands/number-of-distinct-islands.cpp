// User function Template for C++

class Solution {
  public:
    void solve(int r,int c,vector<vector<int>>&g,vector<vector<int>>&vis,  vector<pair<int,int>>&v,int ro,int co){
        vis[r][c]=1;
        int m=g.size();
        int n=g[0].size();
        v.push_back({r-ro,c-co});
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=r+delr[i];
            int ncol=c+delc[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n &&g[nrow][ncol]==1 && vis[nrow][ncol]!=1){
                solve(nrow,ncol,g,vis,v,ro,co);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
      int m=grid.size();
      int n=grid[0].size();
      set<vector<pair<int,int>>>st;
      vector<vector<int>>vis(m,vector<int>(n,0));
      for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
              if(grid[i][j]==1 && !vis[i][j]){
                  vector<pair<int,int>>v;
                  solve(i,j,grid,vis,v,i,j);
                  st.insert(v);
              }
          }
      }
      return st.size();
    }
};
