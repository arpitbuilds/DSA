class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(),coins.end());
        int cnt=1;
        for(int i=0;i<coins.size();i++){
            if(coins[i]<=cnt){
                cnt+=coins[i];
            }
            else{
                return cnt;
            }
        }
        return cnt;
    }
};