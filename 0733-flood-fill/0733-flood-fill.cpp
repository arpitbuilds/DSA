class Solution {
public:
    void dfs(int inic,int sr,int sc,vector<vector<int>>& img,vector<vector<int>>& ans,int color){
        ans[sr][sc]=color;
        int r=sr;
        int c=sc;
        int m=img.size();
        int n=img[0].size();
          int drow[]={-1,0,1,0};
      int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && img[nrow][ncol]==inic && ans[nrow][ncol]!=color){
                dfs(inic,nrow,ncol,img,ans,color);

            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        int inic=image[sr][sc];
        dfs(inic,sr,sc,image,ans,color);
        return ans;
    }
};