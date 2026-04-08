class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int pf=0;
        for(int i=0;i<n;i++){
            ans[i]=pf+nums[i];
            pf+=nums[i];
        }
        return ans;
    }
};