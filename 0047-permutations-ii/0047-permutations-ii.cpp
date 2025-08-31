class Solution {
public:
    void solve(vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans, vector<int>& freq) {
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!freq[i]){
                // Skip duplicates: if current num == previous num and previous wasn't used
                if(i > 0 && nums[i] == nums[i-1] && !freq[i-1]) continue;

                ds.push_back(nums[i]);
                freq[i] = 1;
                solve(nums, ds, ans, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> freq(nums.size(), 0);
        
        sort(nums.begin(), nums.end()); // ✅ sort first
        solve(nums, ds, ans, freq);
        return ans;
    }
};
