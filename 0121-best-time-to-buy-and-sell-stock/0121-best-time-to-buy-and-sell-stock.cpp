class Solution {
public:
    int maxProfit(vector<int>& p) {
       int mini=p[0];
       int maxi=0;
       for(int i=1;i<p.size();i++){
         int profit=p[i]-mini;
         maxi=max(maxi,profit);
         mini=min(mini,p[i]);
       }
       return maxi;
    }
};