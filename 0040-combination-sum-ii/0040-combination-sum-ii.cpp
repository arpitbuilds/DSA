class Solution {
public:
    void solve(int ind,vector<int>&v,vector<vector<int>>&ans,int t,vector<int>&c){
        if(t==0){
            ans.push_back(v);
            return ;
        }
        for(int i=ind;i<c.size();i++){
            if(i>ind && c[i]==c[i-1]){
                continue;
            }
            if(c[i]>t){
                break;
            }
            v.push_back(c[i]);
            solve(i+1,v,ans,t-c[i],c);
            v.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        sort(candidates.begin(),candidates.end());
        solve(0,v,ans,target,candidates);
        return ans;
    }
};