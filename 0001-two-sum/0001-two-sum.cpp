class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};



// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> mpp;
//         int n = nums.size();
//         for (int i = 0; i < n; i++) {
//             int rem = target - nums[i];
//             if (mpp.find(rem) != mpp.end()) {
//                 return {i, mpp[rem]};
//             }
//             mpp[nums[i]] = i;
//         }
//         return {};
//     }
// };