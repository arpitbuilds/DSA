class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st;
        int maxi=0;
        int cnt=0;
        int cn=0;
        for(auto it : nums){
            st.insert(it);
        }
        for(auto it : st){
            if(st.find(it-1)==st.end()){
                 cn=it;
                 cnt=1;
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