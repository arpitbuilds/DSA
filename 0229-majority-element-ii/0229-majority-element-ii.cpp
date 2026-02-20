class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0;
        int cnt2 = 0;
        int ele1 = 0;
        int ele2 = 0;
        int n =nums.size();
        for (auto it : nums) {
            if (it == ele1) {
                cnt1++;
            } else if (it == ele2) {
                cnt2++;
            } else if (cnt1 == 0) {
                cnt1++;
                ele1 = it;
            } else if (cnt2 == 0) {
                cnt2++;
                ele2 = it;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for(auto it : nums){
            if(it==ele1){
                cnt1++;
            }
            if(it==ele2){
                cnt2++;
            }
        }
        vector<int>ans;
        if(cnt1>n/3){
            ans.push_back(ele1);
        }
        if(cnt2>n/3 && ele1!=ele2){
            ans.push_back(ele2);
        }
        return ans;
    }
};