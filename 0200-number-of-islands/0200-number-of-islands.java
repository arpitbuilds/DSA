class Solution {
    public void solve(int i,int j,boolean[][]vis,char[][]grid){
        vis[i][j]=true;
        int m=grid.length;
        int n=grid[0].length;
        int []dr={0,-1,0,1};
        int []dc={-1,0,1,0};
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]=='1'){
                solve(nr,nc,vis,grid);
            }
        }
    }
    public int numIslands(char[][] grid) {
        int m=grid.length;
        int n=grid[0].length;
        boolean[][]vis=new boolean[m][n];
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    solve(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
}