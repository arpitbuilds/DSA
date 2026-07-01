class Solution {
public:
    void solve(int r,int c,vector<vector<int>>&img,int color,int inic){
        int m=img.size();
        int n=img[0].size();
        img[r][c]=color;
        int delr[]={0,-1,0,1};
        int delc[]={-1,0,1,0};
        for(int k=0;k<4;k++){
            int nr=r+delr[k];
            int nc=c+delc[k];
            if(nr>=0 && nc>=0 && nr<m && nc<n && img[nr][nc]==inic && img[nr][nc]!=color){
                solve(nr,nc,img,color,inic);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        int m=img.size();
        int n=img[0].size();
        int inic=img[sr][sc];
        solve(sr,sc,img,color,inic);
        return img;
    }
};