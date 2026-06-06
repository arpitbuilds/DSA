class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxi=0;
        unordered_set<int>st;
        for(auto it : nums){
            st.insert(it);
        }
        for(auto it : st){
            if(st.find(it-1)==st.end()){
                int cn=it;
                int cnt=1;
                while(st.find(cn+1)!=st.end()){
                    cn++;
                    cnt++;
                }
                maxi=max(cnt,maxi);
            }
        }
        return maxi;
    }
};