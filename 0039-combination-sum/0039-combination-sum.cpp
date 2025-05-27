class Solution {
public:
    void solve(int ind,vector<int>&given,int target,vector<int>&v,vector<vector<int>>&res){
        if(ind==given.size()){
            if(target==0){
            res.push_back(v);
            }
            return;
        }
        if(given[ind]<=target){
            v.push_back(given[ind]);
            solve(ind,given,target-given[ind],v,res);
            v.pop_back();
        }
        solve(ind+1,given,target,v,res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>v;
        vector<vector<int>>res;
        solve(0,candidates,target,v,res);
        return res;
        
    }
};