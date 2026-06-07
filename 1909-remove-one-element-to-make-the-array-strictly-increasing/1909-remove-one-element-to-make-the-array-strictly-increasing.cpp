class Solution {
public:
    bool isStrictlyIncreasing(vector<int>& arr) {
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] <= arr[i - 1]) {
                return false;
            }
        }
        return true;
    }

    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            vector<int> temp = nums;
            temp.erase(temp.begin() + i);

            if (isStrictlyIncreasing(temp)) {
                return true;
            }
        }

        return false;
    }
};