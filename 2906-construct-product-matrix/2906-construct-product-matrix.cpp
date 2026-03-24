class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int mod=12345;
        long long suffix=1;
        long long preffix=1;
         vector<vector<int>> ans(m, vector<int>(n, 1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=preffix;
                preffix=(preffix*grid[i][j])%mod;
            }
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                ans[i][j]=(suffix*ans[i][j])%mod;
                suffix=(suffix*grid[i][j])%mod;
            }
        }
        return ans;
    }
};