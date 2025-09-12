class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto x:nums){
            st.insert(x);
        }
        int maxi=0;
        for(int num:st){
            if(st.find(num-1)==st.end()){
                int cn=num;
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