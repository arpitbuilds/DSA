class Solution {
public:
    void solve(int ind,int n,int k,vector<int>&ans,vector<vector<int>>&res){
        if(ind>n){
            if(ans.size()==k){
                res.push_back(ans);
            }
             return;
        }
        ans.push_back(ind);
        solve(ind+1,n,k,ans,res);
        ans.pop_back();
        solve(ind+1,n,k,ans,res);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>ans;
        vector<vector<int>>res;
        solve(1,n,k,ans,res);
        return res;
    }
};