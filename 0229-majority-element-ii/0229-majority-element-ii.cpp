class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0;
        vector<int>ans;
        int n=nums.size();
        int cnt2 = 0;
        int a = 0;
        int b = 0;
        for (auto it : nums) {
            if (a == it) {
                cnt1++;
            } else if (b == it) {
                cnt2++;
            } else if (cnt1 == 0) {
                a = it;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                b = it;
                cnt2 = 1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for (auto it : nums) {
            if (it == a) {
                cnt1++;
            } else if (it == b) {
                cnt2++;
            }
        }
        if (cnt1 > n / 3) {
            ans.push_back(a);
        }
        if (cnt2 > n / 3 && a != b) {
            ans.push_back(b);
        }
        return ans;
    }
};