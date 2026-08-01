class Solution {
public:
    void solve(int oc,int cc,int n,string s,vector<string>&v){
       if(oc==n && cc==n){
        v.push_back(s);
        return ;
       } 
       if(oc<n){
        solve(oc+1,cc,n,s+"(",v);
       }
       if(cc<oc){
        solve(oc,cc+1,n,s+")",v);
       }
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        vector<string>v;
        int oc=0;
        int cc=0;
        solve(oc,cc,n,s,v);
        return v;
    }
};