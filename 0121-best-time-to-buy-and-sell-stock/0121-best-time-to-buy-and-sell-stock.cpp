class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int mini=prices[0];
        int n=prices.size();
        for(int i=1;i<n;i++){
            maxi=max(maxi,prices[i]-mini);
            if(prices[i]<mini){
                mini=prices[i];
            }
        }
        return maxi;
    }
};