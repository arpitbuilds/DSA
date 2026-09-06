class Solution {
public:
    int maxProfit(vector<int>& p) {
        int pr=0;
        int mini=p[0];
        for(int i=0;i<p.size();i++){
            int dif=p[i]-mini;
            pr=max(pr,dif);
            mini=min(mini,p[i]);
        }
        return pr;
    }
};