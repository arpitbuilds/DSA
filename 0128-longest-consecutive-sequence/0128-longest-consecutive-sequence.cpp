class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        unordered_set<int>st(nums.begin(),nums.end());
        for(auto it : st){
            if(st.find(it-1)==st.end()){
                int cnt=1;
                int cn=it;
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