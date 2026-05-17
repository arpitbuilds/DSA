class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int,int> mpp;

        mpp[0] = 1;

        int pf = 0;
        int cnt = 0;

        for(auto it : nums) {

            pf += it;

            int rem = pf % k;

            // Handle negative remainder
            if(rem < 0)
                rem += k;

            if(mpp.find(rem) != mpp.end()) {
                cnt += mpp[rem];
            }

            mpp[rem]++;
        }

        return cnt;
    }
};