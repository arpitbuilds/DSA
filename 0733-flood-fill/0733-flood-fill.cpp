class Solution {
public:
    void dfs(int sr,int sc,int inic,vector<vector<int>>& ans,vector<vector<int>>& img,int color){
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
        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && ans[nrow][ncol]!=color && img[nrow][ncol]==inic ){
            dfs(nrow,ncol,inic,ans,img,color);
        }
      }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        int inic=image[sr][sc];
        dfs(sr,sc,inic,ans,image,color);
        return ans;
    }
};