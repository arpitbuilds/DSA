class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int tot=m*n;
        int s=0;
        int e=tot-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int crow=mid/n;
            int ccol=mid%n;
            if(matrix[crow][ccol]==target){
                return true;
            }
            else if(matrix[crow][ccol]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return false;
    }
};