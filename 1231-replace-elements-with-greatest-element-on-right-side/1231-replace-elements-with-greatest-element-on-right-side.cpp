class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int j=arr.size()-1;
        int maxi=-1;
        int n=arr.size();
        vector<int>nums(n);
        while(j>=0){
            nums[j]=maxi;
            maxi=max(arr[j],maxi);
            j--;
        }
        return nums;
    }
};