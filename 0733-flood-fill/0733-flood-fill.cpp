class Solution {
public:
    void solve(int inic,int sr,int sc,vector<vector<int>>&img,vector<vector<int>>&ans,int m,int n,int color){
        ans[sr][sc]=color;
        int delr[] = {0, -1, 0, 1};
        int delc[] = {-1, 0, 1, 0};
        for(int i=0;i<4;i++){
            int nrow=sr+delr[i];
            int ncol=sc+delc[i];
            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && img[nrow][ncol]==inic && ans[nrow][ncol]!=color){
                solve(inic,nrow,ncol,img,ans,m,n,color);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        int m=img.size();
        int n=img[0].size();
        int inic=img[sr][sc];
        vector<vector<int>>ans=img;
        solve(inic,sr,sc,img,ans,m,n,color);
        return ans;
    }
};