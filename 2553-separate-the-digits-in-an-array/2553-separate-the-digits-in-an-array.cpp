class Solution {
public:
    void solve(int x,vector<int>&ans){
        vector<int>temp;
        while(x!=0){
            int digit=x%10;
            temp.push_back(digit);
            x=x/10;
        }
        reverse(temp.begin(), temp.end());

        for (auto it : temp) {
            ans.push_back(it);
        }
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(auto it : nums){
            solve(it,ans);
        }
        return ans;
    }
};