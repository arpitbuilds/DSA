class Solution {
public:
    void solve(int ind,vector<int>&given,int target,vector<int>&v,set<vector<int>>&res){
        if(ind==given.size()){
            if(target==0){
            res.insert(v);
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
        set<vector<int>>res;
        solve(0,candidates,target,v,res);
        vector<vector<int>>ans(res.begin(),res.end());
        return ans;
        
    }
};