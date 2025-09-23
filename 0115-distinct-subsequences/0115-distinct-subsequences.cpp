class Solution {
public:
     int dp_mem(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
  
    if (j < 0) return 1; 
    if (i < 0) return 0; 
    
    if (dp[i][j] != -1) return dp[i][j];
  
    if (s[i] == t[j])
        return dp[i][j] = dp_mem(i-1, j-1, s, t, dp) + dp_mem(i-1, j, s, t, dp);
    
    return dp[i][j] = dp_mem(i-1, j, s, t, dp);
}
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return dp_mem(m-1,n-1,s,t,dp);
        
    }
};