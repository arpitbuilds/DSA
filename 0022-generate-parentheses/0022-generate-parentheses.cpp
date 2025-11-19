class Solution {
public:
    void solve(string s,vector<string>&ans,int oc,int cc, int n ){
        if(oc==n && cc==n){
            ans.push_back(s);
            return ;
        }
        if(oc<n){
            solve(s+'(',ans,oc+1,cc,n);
        }
        if(cc<oc){
            solve(s+')',ans,oc,cc+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        vector<string>v;
        int oc=0;
        int cc=0;
        solve(s,v,oc,cc,n);
        return v;
        
    }
};