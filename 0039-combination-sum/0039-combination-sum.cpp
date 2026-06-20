class Solution {
public:
    void solve(int ind,vector<int>&c,vector<vector<int>>&ans,vector<int>&v,int t){
        if(ind==c.size()){
            if(t==0){
                ans.push_back(v);
            }
            return;
        }
        if(c[ind]<=t){
            v.push_back(c[ind]);
            solve(ind,c,ans,v,t-c[ind]);
            v.pop_back();
        }
        solve(ind+1,c,ans,v,t);
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        solve(0,c,ans,v,target);
        return ans;
    }
};