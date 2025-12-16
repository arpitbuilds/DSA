class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        for(auto it : nums){
            if(val != it){
                nums[i]=it;
                i++;
            }
        }
        return i;
    }
};