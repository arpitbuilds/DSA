class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto x : nums1) {
            pq.push(x);
        }
        for (auto x : nums2) {
            pq.push(x);
        }
        int total = nums1.size() + nums2.size();
        int mid = total / 2;
        int prev = 0;
        int cur = 0;
        for (int i = 0; i <= mid; i++) {
            prev = cur;
            cur = pq.top();
            pq.pop();
        }
        if(total%2==1){
            return cur;
        }
        return (prev+cur)/2.0;
    }
};