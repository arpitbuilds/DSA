class Solution {
public: 
    vector<vector<int>>ans;
    void solve(int ind,vector<int>&v,vector<int>&c,int t){
        if(ind==c.size()){
            if(t==0){
                ans.push_back(v);
            }
            return ;
        }
        if(c[ind]<=t){
            v.push_back(c[ind]);
            solve(ind,v,c,t-c[ind]);
            v.pop_back();
        }
        solve(ind+1,v,c,t);
    }
    vector<vector<int>> combinationSum(vector<int>c, int target) {
        //vector<vector<int>>ans;
        vector<int>v;
        solve(0,v,c,target);
        return ans;
    }
};