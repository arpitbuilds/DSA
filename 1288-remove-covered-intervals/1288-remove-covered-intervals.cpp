class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& inn) {
        sort(inn.begin(), inn.end(),
             [](vector<int>& a, vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
             });
        // vector<vector<int>> v;
        int cnt = 0;
        int n = inn.size();
        vector<int> fe = inn[0];
        for (int i = 1; i < inn.size(); i++) {
            if (inn[i][0] >= fe[0] && inn[i][1] <= fe[1]) {
                cnt++;
            } else {
                fe = inn[i];
            }
        }
        int ans = n - cnt;
        return ans;
    }
};