class Solution {
public:
    void solve(int oc,int cc,vector<string>&ans,string t,int n){
        if(oc==n && cc==n){
            ans.push_back(t);
            return ;
        }
        if(oc<n){
            solve(oc+1,cc,ans,t+'(',n);
        }
        if(cc<oc){
            solve(oc,cc+1,ans,t+')',n);
        }
    }
    vector<string> generateParenthesis(int n) {
        int oc=0;
        int cc=0;
        vector<string>ans;
        string temp="";
        solve(oc,cc,ans,temp,n);
        return ans;
    }
};