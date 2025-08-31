class Solution {
public:
    void solve(int idx,vector<int>&ds,int t,vector<int>&given,vector<vector<int>>&ans){
        if(t==0){
            ans.push_back(ds);
            return;
        }
        for(int i=idx;i<given.size();i++){
            if(i>idx && given[i]==given[i-1]){
                continue;
            }
            if(given[i]>t){
                break;
            }
            ds.push_back(given[i]);
            solve(i+1,ds,t-given[i],given,ans);
            ds.pop_back();

        }


    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>ds;
        vector<vector<int>>ans;
        int idx=0;
        sort(candidates.begin(),candidates.end());
        solve(idx,ds,target,candidates,ans);
        return ans;
    }
};