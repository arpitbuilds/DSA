class Solution {
public:
    void solve(int ind,int &sum,vector<int>&nums,vector<int>&ans){
        if(ind>=nums.size()){
            int xorr=0;
            for(auto it : ans){
                xorr=xorr^it;
            }
            sum+=xorr;
            return ;
        }
        ans.push_back(nums[ind]);
        solve(ind+1,sum,nums,ans);
        ans.pop_back();
        solve(ind+1,sum,nums,ans);
    }
    int subsetXORSum(vector<int>& nums) {
        int ind=0;
        vector<int>ans;
        int sum=0;
        solve(0,sum,nums,ans);
        return sum;
    }
};