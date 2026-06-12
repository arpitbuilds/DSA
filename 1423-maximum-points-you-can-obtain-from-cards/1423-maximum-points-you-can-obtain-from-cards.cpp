class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int lsum=0;
        int rsum=0;
        
        for(int i=0;i<k;i++){
            lsum+=cp[i];
        }
        int maxi=lsum;
        int n=cp.size();
        int r=n-1;
        for(int i=k-1;i>=0;i--){
            lsum-=cp[i];
            rsum+=cp[r];
            r--;
            maxi=max(maxi,lsum+rsum);
        }
        return maxi;
    }
};