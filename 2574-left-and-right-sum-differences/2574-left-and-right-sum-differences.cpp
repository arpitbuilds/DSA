class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>lefts(n,0);
        vector<int>rights(n,0);
        for(int i=1;i<n;i++){
            lefts[i]=lefts[i-1]+nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            rights[i]=rights[i+1]+nums[i+1];
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=abs(lefts[i]-rights[i]);
        }
        return ans;
    }
};