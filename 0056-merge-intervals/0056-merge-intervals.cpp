class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& given) {
        sort(given.begin(), given.end());
        vector<vector<int>> ans;
        ans.push_back(given[0]);
        for (int i = 1; i < given.size(); i++) {
            if (ans.back()[1] >= given[i][0]) {
                ans.back()[1] = max(ans.back()[1], given[i][1]);
            } else {
                ans.push_back(given[i]);
            }
        }
        return ans;
    }
};