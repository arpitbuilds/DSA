class Solution {
public:
    void solve(vector<int>&nums,int ind,vector<vector<int>>&res,vector<int>&sub){
        if(ind==nums.size()){
            res.push_back(sub);
            return ;
        }
        sub.push_back(nums[ind]);
        solve(nums,ind+1,res,sub);
        sub.pop_back();
        solve(nums,ind+1,res,sub);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>sub;
        solve(nums,0,res,sub);
        return res;
        
    }
};