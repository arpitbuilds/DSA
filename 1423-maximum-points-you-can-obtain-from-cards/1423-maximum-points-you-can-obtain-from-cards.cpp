class Solution {
public:
    int maxScore(vector<int>&p, int k) {
        int tsum=0;
        for(auto it : p ){
            tsum+=it;
        }
        int n=p.size();
        int maxi=0;
        int lsum=0;
        for(int i=0;i<k;i++){
            lsum+=p[i];
        }
        maxi=lsum;
        int r=n-1;
        int rsum=0;
        for(int i=k-1;i>=0;i--){
            lsum-=p[i];
            rsum+=p[r];
            maxi=max(maxi,lsum+rsum);
            r--;
        }
        return maxi;
    }
};