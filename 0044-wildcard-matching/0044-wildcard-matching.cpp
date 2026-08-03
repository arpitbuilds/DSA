class Solution {
public:
    bool solve(string &s,string &p,int m,int n,vector<vector<int>>&dp){
        if(m<0 && n<0){
            return true;
        }
        if(m>=0 && n<0){
            return false;
        }
        if(m<0 && n>=0){
            int k=n;
            for(int i=k;i>=0;i--){
                if(p[i]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        if(s[m]==p[n] || p[n]=='?'){
            return dp[m][n]=solve(s,p,m-1,n-1,dp);
        }
        else if(p[n]=='*'){
            return dp[m][n]=solve(s,p,m-1,n,dp) || solve(s,p,m,n-1,dp);
        }
        return dp[m][n]=false;
    }
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(s,p,m-1,n-1,dp);
    }
};