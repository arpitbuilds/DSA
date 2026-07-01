class Solution {
public:
    int countElements(vector<int>& nums) {
      int n=nums.size();
      set<int>st(nums.begin(),nums.end());
      if(st.size()==1){
        return 0;
      }
      int maxi=*max_element(nums.begin(),nums.end());
      int mini=*min_element(nums.begin(),nums.end());
      int cnt1=count(nums.begin(),nums.end(),maxi);
      int cnt2=count(nums.begin(),nums.end(),mini);
      int ans=n-(cnt1+cnt2);
      return ans;
    }
};