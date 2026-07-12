class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto it : nums){
            mpp[it]++;
        }
        int n=nums.size();
        int ele=nums[n/2];
        if(mpp[ele]==1){
            return true;
        }
        return false;
    }
};