class Solution {
public:
    void solve(int ind,vector<vector<int>>&ans,vector<int>&v,vector<int>&c,int t){
        if(ind==c.size()){
            if(t==0){
                ans.push_back(v);
            }
              return;
        }
        if(c[ind]<=t){
            v.push_back(c[ind]);
            solve(ind+1,ans,v,c,t-c[ind]);
            v.pop_back();
        }
        while(ind+1<c.size()  && c[ind]==c[ind+1]){
            ind++;
        }
        solve(ind+1,ans,v,c,t);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        sort(candidates.begin(),candidates.end());
        solve(0,ans,v,candidates,target);
        return ans;
    }
};