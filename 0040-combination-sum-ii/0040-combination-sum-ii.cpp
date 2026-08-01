class Solution {
public:
        vector<vector<int>>ans;
    void solve(int ind,vector<int>&v,vector<int>&c,int t){
        int n=c.size();
        if(ind==c.size()){
            if(t==0){
                ans.push_back(v);
            }
            return ;
        }
        if(c[ind]<=t){
            v.push_back(c[ind]);
            solve(ind+1,v,c,t-c[ind]);
            v.pop_back();
        }
        while(ind+1<n && c[ind]==c[ind+1]){
            ind++;
        }
        solve(ind+1,v,c,t);
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<int>v;
        sort(c.begin(),c.end());
        solve(0,v,c,target);
        return ans;
    }
};