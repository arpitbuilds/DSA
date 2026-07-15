class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int s=m*n;
        vector<int>freq(s+1,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                freq[grid[i][j]]++;
            }
        }
        int r=0;
        int x=0;
        for(int i=1;i<=s;i++){
            if(freq[i]==0){
               x=i;
            }
            if(freq[i]==2){
                r=i;
            }
        }
        return {r,x};
    }
};