class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto x : nums1){
            pq.push(x);
        }
        for(auto x : nums2){
            pq.push(x);
        }
        int tot=nums1.size()+nums2.size();
        int prev=0;
        int cur=0;
        int mid=tot/2;
        for(int i=0;i<=mid;i++){
            prev=cur;
            cur=pq.top();
            pq.pop();
        }
        if(tot%2==1){
            return cur;
        }
        return (prev+cur)/2.0;
    }
};