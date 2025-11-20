class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        
        int dup = -1, missing = -1;

        for(int x : nums) mpp[x]++;

        for(int i = 1; i <= n; i++) {
            if(mpp[i] == 2) dup = i;
            if(mpp[i] == 0) missing = i;
        }

        return {dup, missing};   // correct order
    }
};
