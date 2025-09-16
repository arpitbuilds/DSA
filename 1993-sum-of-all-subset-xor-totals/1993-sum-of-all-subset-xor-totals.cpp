class Solution {
public:
     void solve(int ind,int &ans,vector<int>& nums,vector<int>&sub){
        if(ind==nums.size()){
            int xorr=0;
            for(auto num:sub){
                xorr=xorr^num;
            }
            ans+=xorr;
            return;
        }
        sub.push_back(nums[ind]);
        solve(ind+1,ans,nums,sub);
        sub.pop_back();
        solve(ind+1,ans,nums,sub);
     }
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        vector<int>subsets;
        solve(0,ans,nums,subsets);
        return ans;
    }
};