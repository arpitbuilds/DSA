class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        unordered_map<int,int> mpp;

        mpp[0] = 1;

        int pf = 0;
        int cnt = 0;

        for(auto it : nums) {

            pf += it;

            int rem = pf - goal;

            if(mpp.find(rem) != mpp.end()) {
                cnt += mpp[rem];
            }

            mpp[pf]++;
        }

        return cnt;
    }
};