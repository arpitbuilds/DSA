class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> mpp;

        int m = nums.size();

        // same as yours (top → bottom works fine)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                mpp[i + j].push_back(nums[i][j]);
            }
        }

        vector<int> ans;

        for (auto it : mpp) {
            // reverse EVERY diagonal
            reverse(it.second.begin(), it.second.end());

            for (auto x : it.second) {
                ans.push_back(x);
            }
        }

        return ans;
    }
};