class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>v=nums;
        sort(v.begin(),v.end());
        int i=0;
        while(i<nums.size() && nums[i]==v[i]){
            i++;
        }
        int j=nums.size()-1;
        while(j>=0 && nums[j]==v[j]){
            j--;
        }
        if(i<j){
            return (j-i+1);
        }
        return 0;
    }
};