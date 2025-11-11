class Solution {
public:
    // bool solve(int x ,int y ,string s,string p, vector<vector<int>>&dp){
    //     if(x==0 && y==0){
    //         return true;
    //     }
    //     if(x==0 && y>0){
    //         for(int i=1;i<=y;i++){
    //             if(p[i-1]!='*'){
    //                 return false;
    //             }

    //         }
    //          return true;
    //     }
    //     if(x>0 && y==0){
    //         return false;
    //     }
    //     if(dp[x][y]!=-1){
    //         return dp[x][y];
    //     }
    //     if(s[x-1]==p[y-1]  || p[y-1]=='?'){
    //         return dp[x][y]=solve(x-1,y-1,s,p,dp);
    //     }
    //     if(p[y-1]=='*'){
    //         return dp[x][y]=solve(x-1,y,s,p,dp)|| solve(x,y-1,s,p,dp);
    //     }
    //     return dp[x][y]=false;
    // }
    bool isMatch(string s, string p) {
        int x = s.size();
        int y = p.size();
        vector<vector<bool>> dp(x + 1, vector<bool>(y+1, false));
        // return solve(x,y,s,p,dp);
        dp[0][0] = true;
        for (int i = 1; i <= x; i++) {
            dp[i][0] = false;
        }
        for (int j = 1; j <= y; j++) {
            bool flag = true;
            for (int i = 1; i <= j; i++) {
                if (p[i - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[x][y];
    }
};