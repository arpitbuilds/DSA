class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f,
                                             vector<vector<int>>& s) {
        int m = f.size();
        int n = s.size();
        vector<vector<int>> ans;
        int i = 0;
        int j = 0;
        while (i < m && j < n) {
            int s1 = f[i][0];
            int s2 = s[j][0];
            int e1 = f[i][1];
            int e2 = s[j][1];
            int s = max(s1, s2);
            int e = min(e1, e2);
            if (s <=e) {
                ans.push_back({s, e});
            }
            if (e1 < e2) {
                i++;
            } else {
                j++;
            }
        }
        return ans;
    }
};