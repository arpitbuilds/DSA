class Solution {
public:
    int solve(int x){
        int sum=0;
        while(x!=0){
            int digit=x%10;
            sum+=digit;
            x=x/10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        for(auto x : nums){
            mini=min(mini,solve(x));
        }
        return mini;
    }
};