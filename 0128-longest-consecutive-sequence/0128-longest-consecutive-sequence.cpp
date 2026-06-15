class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st;
        for(auto it : nums){
            st.insert(it);
        }
        int maxi=0;
        for(auto it : st){
            if(st.find(it-1)==st.end()){
                int cn=it;
                int cnt=1;
                while(st.find(cn+1)!=st.end()){
                    cn++;
                    cnt++;
                }
                maxi=max(maxi,cnt);
            }
        }
        return maxi;
    }
};