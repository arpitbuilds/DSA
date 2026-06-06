class Solution {
public:
    void solve(int oc,int cc,string t,vector<string>&ans,int n){
        if(oc==n && cc==n){
            ans.push_back(t);
            return ;
        }
        if(oc<n){
            solve(oc+1,cc,t+'(',ans,n);
        }
        if(cc<oc){
            solve(oc,cc+1,t+')',ans,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        int oc=0;
        int cc=0;
        string temp="";
        vector<string>ans;
        solve(oc,cc,temp,ans,n);
        return ans;
    }
};