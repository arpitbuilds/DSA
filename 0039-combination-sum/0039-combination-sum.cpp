class Solution {
public:
    void solve(int ind,vector<int>&v,vector<vector<int>>&ans,int t,vector<int>&c){
        if(ind==c.size()){
            if(t==0){
                ans.push_back(v);
                
            }
            return ;
        }
        if(c[ind]<=t){
            v.push_back(c[ind]);
            solve(ind,v,ans,t-c[ind],c);
            v.pop_back();
        }
        solve(ind+1,v,ans,t,c);
    } 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>v;
        vector<vector<int>>ans;
        solve(0,v,ans,target,candidates);
        return ans;
    }
};