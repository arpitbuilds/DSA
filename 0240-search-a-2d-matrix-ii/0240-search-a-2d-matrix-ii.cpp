class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m=mat.size();
        int n=mat[0].size();
        int crow=0;
        int ccol=n-1;
        while(crow<m && ccol>=0){
            int ele=mat[crow][ccol];
            if(ele==target){
                return true;
            }
            else if(mat[crow][ccol]<target){
                crow++;
            }
            else{
                ccol--;
            }
        }
        return false;
    }
};