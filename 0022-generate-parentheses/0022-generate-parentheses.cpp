class Solution {
public:
    void solve(int n,int oc,int cc,vector<string>&ans,string s){
        if(oc==n && cc==n){
            ans.push_back(s);
            return ;
        }
        if(oc<n){
            solve(n,oc+1,cc,ans,s+'(');
        }
        if(cc<oc){
            solve(n,oc,cc+1,ans,s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        int oc=0;
        int cc=0;
        vector<string>ans;
        string s="";
        solve(n,oc,cc,ans,s);
        return ans;
    }
};