class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        int pf=nums[0];
        vector<int>ans(n);
        ans[0]=pf;
        for(int i=1;i<n;i++){
             pf+=nums[i];
             ans[i]=pf;

        }
return ans;
    }
};