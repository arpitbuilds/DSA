class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& i) {
        int n = i.size();
        vector<pair<int, int>> v;
        for (auto it : i) {
            v.push_back({it[1], it[0]});
        }
        int cnt = 0;
        sort(v.begin(), v.end());
        int fe = v[0].first;
        for (int i = 1; i < n; i++) {
            if (v[i].second < fe) {
                cnt++;
            } else {
                fe = v[i].first;
            }
        }
        return cnt;
    }
};