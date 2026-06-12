class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        int mini=p[0];
        //int cost=0;
        int pr=0;
        for(int i=1;i<n;i++){
            pr=max(pr,p[i]-mini);
            if(p[i]<mini){
                mini=min(mini,p[i]);
            }
        }
        return pr;
    }
};