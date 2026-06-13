class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inn, vector<int>& newi) {
        vector<vector<int>> ans;
        int i = 0;
        int n = inn.size();
        while (i < n) {
            while (i < n && inn[i][1] < newi[0]) {
                ans.push_back(inn[i]);
                i++;
            }
            if (i<n && inn[i][0] > newi[1]) {
                break;
            } else if(i<n) {
                newi[0] = min(newi[0], inn[i][0]);
                newi[1] = max(newi[1], inn[i][1]);
                i++;
            }
        }
        ans.push_back(newi);
        while (i < n) {
            ans.push_back(inn[i]);
            i++;
        }
        return ans;
    }
};