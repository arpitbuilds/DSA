class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int>mpp;
        for(int i=0;i<grid.size();i++){
            mpp[grid[i]]++;
        }
        int cnt=0;
        for(int i=0;i<grid[0].size();i++){
            vector<int>ans;
            for(int j=0;j<grid.size();j++){
                ans.push_back(grid[j][i]);
            }
            cnt+=mpp[ans];
        }
        return cnt;
    }
};