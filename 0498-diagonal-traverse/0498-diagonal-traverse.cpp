class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>ans;
        map<int,vector<int>>mpp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              mpp[i+j].push_back(mat[i][j]);
            }
        }
        bool flag=true;
        for(auto it : mpp){
            if(flag){
                reverse(it.second.begin(),it.second.end());
            }
            for(auto x : it.second){
                ans.push_back(x);
            }
            flag=!flag;
        }
        return ans;
    }
};