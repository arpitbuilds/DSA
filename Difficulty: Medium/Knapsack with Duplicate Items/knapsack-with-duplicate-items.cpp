class Solution {
  public:
    int solve(int ind,vector<int>&v,vector<int>&w,int c,vector<vector<int>>&dp){
        if(ind==0){
           
              
        return (c / w[ind]) * v[ind];
   
        }
        if(dp[ind][c]!=-1){
            return dp[ind][c];
        }
        int ntake=0+solve(ind-1,v,w,c,dp);
        int take=INT_MIN;
        if(c>=w[ind]){
            take=v[ind]+solve(ind,v,w,c-w[ind],dp);
        }
        return dp[ind][c]=max(take,ntake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        return solve(n-1,val,wt,capacity,dp);
        
    }
};