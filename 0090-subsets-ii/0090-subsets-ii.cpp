class Solution {
public:
  void solve(vector<int>&nums,int ind,set<vector<int>>&res,vector<int>&sub){
        if(ind==nums.size()){
            res.insert(sub);
            return ;
        }
        sub.push_back(nums[ind]);
        solve(nums,ind+1,res,sub);
        sub.pop_back();
        solve(nums,ind+1,res,sub);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        set<vector<int>> res;
        vector<int>sub;
        solve(nums,0,res,sub);
        vector<vector<int>> result(res.begin(),res.end());
        return result;
    }
};