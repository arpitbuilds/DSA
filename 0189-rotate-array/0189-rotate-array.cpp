class Solution {
public:
    void reversee(vector<int>&v,int s ,int e){
        while(s<=e){
            swap(v[s],v[e]);
            s++;
            e--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reversee(nums,0,n-1);
        reversee(nums,0,k-1);
        reversee(nums,k,n-1);
    }
};