class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int suml=0;
        int sumr=0;
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    suml+=mat[i][j];
                }
                else if(i+j==n-1){
                    sumr+=mat[i][j];
                }
            }
        }
        int ans=suml+sumr;
        return ans;
    }
};