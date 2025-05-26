class Solution {
public:
    void recursiveFunction(set<vector<int>>& ans,vector<int>& nums,int n,int index,vector<int> subset){
        if(index>=n){
            ans.insert(subset);
            return;
        }

        subset.push_back(nums[index]);
        recursiveFunction(ans,nums,n,index+1,subset);
        
        subset.pop_back();
        recursiveFunction(ans,nums,n,index+1,subset);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        set<vector<int>> ans;
        recursiveFunction(ans,nums,n,0,{});
        vector<vector<int>> result(ans.begin(),ans.end());
        return result;
    }
};