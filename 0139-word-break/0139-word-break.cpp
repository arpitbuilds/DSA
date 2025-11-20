class Solution {
public:
    bool solve(int ind,string s,set<string>st,vector<int>&dp){
        if(ind==s.size()){
            return true;
        }
        if(st.find(s)!=st.end()){
            return true;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        for(int i=1;i<=s.size();i++){
            string temp=s.substr(ind,i);
            if(st.find(temp)!=st.end() && solve(ind+i,s,st,dp)){
                return dp[ind]=true;
            }
        }
        return dp[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        set<string>st;
        for(string w :wordDict){
            st.insert(w);
        }
        vector<int>dp(n,-1);
        return solve(0,s,st,dp);
    }
};