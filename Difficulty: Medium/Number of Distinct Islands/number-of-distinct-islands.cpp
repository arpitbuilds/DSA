// User function Template for C++

class Solution {
  public:
    void dfs(int r,int c,vector<vector<int>>& g,vector<vector<int>>& v, vector<pair<int,int>>&vec,int ro,int co){
        v[r][c]=1;
        int m=g.size();
        int n=g[0].size();
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        vec.push_back({r-ro,c-co});
        for(int i=0;i<4;i++){
           int nrow=r+delr[i];
            int ncol=c+delc[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && g[nrow][ncol]==1 && v[nrow][ncol]!=1){
                dfs(nrow,ncol,g,v,vec,ro,co);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m=grid.size();
        int n=grid[0].size();
        set<vector<pair<int,int>>>st;
        vector<vector<int>>v(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && v[i][j]!=1){
                    vector<pair<int,int>>vec;
                    dfs(i,j,grid,v,vec,i,j);
                    st.insert(vec);
                    
                }
            }
        }
        return st.size();
    }
};
