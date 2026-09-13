class Solution {
public:
    long long solve(vector<int>& piles, int x) {
        long long tot = 0;
        for (auto it : piles) {
            tot += ceil((double)it / x);
        }
        return tot;
    }
    int minEatingSpeed(vector<int>& piles, int k) {
        int h = *max_element(piles.begin(), piles.end());
        int l = 1;
        int ans=-1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            long long tot=solve(piles,mid);
            if(tot<=k){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};