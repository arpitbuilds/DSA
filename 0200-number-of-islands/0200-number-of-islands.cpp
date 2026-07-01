class Solution {
public:
    void solve(int r ,int c, vector<vector<char>>&g,vector<vector<int>>&vis){
        int m=g.size();
        int n=g[0].size();
        vis[r][c]=1;
        int delr[]={0,-1,0,1};
        int delc[]={-1,0,1,0};
        for(int k=0;k<4;k++){
            int nr=r+delr[k];
            int nc=c+delc[k];
            if(nr>=0 && nc>=0 && nr<m && nc<n && g[nr][nc]=='1' && !vis[nr][nc]){
                solve(nr,nc,g,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& g) {
        int m=g.size();
        int n=g[0].size();
        int cnt=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    solve(i,j,g,vis);
                }
            }
        }
        return cnt;
    }
};