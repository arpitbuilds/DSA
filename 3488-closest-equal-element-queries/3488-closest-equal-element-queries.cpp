class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int q : queries) {
            vector<int>& pos = mp[nums[q]];

            if (pos.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int idx = lower_bound(pos.begin(), pos.end(), q) - pos.begin();

            int prev = pos[(idx - 1 + pos.size()) % pos.size()];
            int next = pos[(idx + 1) % pos.size()];

            int d1 = abs(q - prev);
            d1 = min(d1, n - d1);

            int d2 = abs(q - next);
            d2 = min(d2, n - d2);

            ans.push_back(min(d1, d2));
        }

        return ans;
    }
};