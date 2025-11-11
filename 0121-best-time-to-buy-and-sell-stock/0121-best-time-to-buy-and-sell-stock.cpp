class Solution {
public:
    int maxProfit(vector<int>& a) {
      int cost=0;
      int p=0;
      int mini=a[0];
      for(int i=1;i<a.size();i++){
        cost=a[i]-mini;
        p=max(p,cost);
        mini=min(mini,a[i]);
      }  
      return p;
    }
};