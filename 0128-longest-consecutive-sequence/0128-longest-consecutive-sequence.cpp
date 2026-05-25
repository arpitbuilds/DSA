class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxi=0;
        int cn=0;
        int cnt=0;
        set<int>st;
        for(auto it : nums){
            st.insert(it);
        }
        for(auto it : st){
            if(st.find(it-1)==st.end()){
                int cnt=1;
                cn=it;
                while(st.find(cn+1)!=st.end()){
                    cnt++;
                    cn++;
                }
                maxi=max(maxi,cnt);
            }
        }
        return maxi;
    }
};