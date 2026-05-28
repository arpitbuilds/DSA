class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m=mat.size();
        int n=mat[0].size();
        int tot=m*n;
        int s=0;
        int e=tot-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int crow=mid/n;
            int ccol=mid%n;
            if(mat[crow][ccol]==target){
                return true;
            }
            else if(mat[crow][ccol]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return false;
    }
};