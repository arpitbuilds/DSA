class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>st;
        set<int>stt;
        vector<int>ans;
        for(auto it : nums1){
            st.insert(it);
        }
        for(auto it : nums2){
            if(st.find(it)!=st.end()){
               stt.insert(it);
            }
        }
        for(auto it :stt){
            ans.push_back(it);
        }
        return ans;
    }
};