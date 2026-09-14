class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it : nums1){
            pq.push(it);
        }
         for(auto it : nums2){
            pq.push(it);
        }
        int n=pq.size();
        int mid=n/2;
        int cur=0;
        int prev=0;
        for(int i=0;i<=mid;i++){
            prev=cur;
            cur=pq.top();
            pq.pop();
        }
        if(n%2==1){
            return cur;
        }
        return double((prev+cur)/2.0);

    }
};