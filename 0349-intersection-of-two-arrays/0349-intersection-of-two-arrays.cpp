class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>st;
        set<int>st1;
        vector<int>ans;
        for(auto it : nums2){
            st.insert(it);
        }
        for(auto it : nums1){
            if(st.find(it)!=st.end()){
               st1.insert(it);
            }
        }
        for(auto it : st1){
            ans.push_back(it);
        }
        return ans;
    }
};