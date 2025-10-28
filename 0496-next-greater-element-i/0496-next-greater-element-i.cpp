class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        vector<int>res(nums1.size(),-1);
        map<int,int>mpp;
        for(auto n : nums2){
            while(!st.empty() && st.top()<n){
                mpp[st.top()]=n;
                st.pop();
            }
            st.push(n);

        }
        for(int i=0;i<nums1.size();i++){
            if(mpp[nums1[i]]){
                res[i]=mpp[nums1[i]];
            }
        }
return res;
    }
};