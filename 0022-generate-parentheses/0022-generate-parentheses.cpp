class Solution {
public:
    void solve(vector<string>&ans,int oc,int cc,int n,string s){
        if(oc==n && cc==n){
            ans.push_back(s);
            return;
        }
        if(oc<n){
            solve(ans,oc+1,cc,n,s+'(');

        }
        if(cc<oc){
            solve(ans,oc,cc+1,n,s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        int oc=0;
        int cc=0;
        solve(ans,oc,cc,n,s);
        return ans;
    }
};