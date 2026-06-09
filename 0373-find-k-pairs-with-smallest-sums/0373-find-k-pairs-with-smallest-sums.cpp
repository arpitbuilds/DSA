class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        priority_queue<pair<int,pair<int,int>>>pq;
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = nums1[i] + nums2[j];
                if (pq.size() < k) {
                    pq.push({sum, {nums1[i], nums2[j]}});
                } else if (pq.top().first > sum) {
                    pq.pop();
                    pq.push({sum, {nums1[i], nums2[j]}});
                } else if (sum >= pq.top().first) {
                    break;
                }
            }
        }
        while (!pq.empty()) {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};