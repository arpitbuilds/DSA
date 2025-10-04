class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0;
        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
        }
        int n=cardPoints.size();
        int r=n-1;
        int maxi=lsum;
        int rsum=0;
        for(int i=k-1;i>=0;i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[r];
            r--;
            maxi=max(maxi,lsum+rsum);
        }
        return lsum;
    }
};