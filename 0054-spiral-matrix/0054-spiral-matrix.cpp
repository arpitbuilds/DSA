class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int sr=0;
        int sc=0;
        int er=m-1;
        int ec=n-1;
        int tot=m*n;
        int cnt=0;
        vector<int>ans;
        while(cnt<tot){
            for(int j=sc;j<=ec &&  cnt < tot;j++){
                ans.push_back(matrix[sr][j]);
                cnt++;
            }
            sr++;
            for(int j=sr;j<=er &&  cnt < tot;j++){
            ans.push_back(matrix[j][ec]);
            cnt++;
            }
            ec--;
            for(int j=ec;j>=sc &&  cnt < tot;j--){
                ans.push_back(matrix[er][j]);
                cnt++;
            }
            er--;
            for(int j=er;j>=sr &&  cnt < tot;j--){
                ans.push_back(matrix[j][sc]);
                cnt++;
            }
            sc++;
        }
  return ans;
    }
};