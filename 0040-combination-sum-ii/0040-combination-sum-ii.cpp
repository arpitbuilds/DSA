class Solution {
public:
    void solve(int ind,vector<vector<int>>&ans,vector<int>&v,vector<int>&c,int target){
        if(ind==c.size()){
            if(target==0){
                ans.push_back(v);
            }
            return;
        }
        if(c[ind]<=target){
            v.push_back(c[ind]);
            solve(ind+1,ans,v,c,target-c[ind]);
            v.pop_back();
        }
        while(ind+1<c.size() && c[ind]==c[ind+1]){
            ind++;
        }
        solve(ind+1,ans,v,c,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        sort(c.begin(),c.end());
        solve(0,ans,v,c,target);
        return ans;

    }
};