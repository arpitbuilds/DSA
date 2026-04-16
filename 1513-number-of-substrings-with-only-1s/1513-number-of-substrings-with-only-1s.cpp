class Solution {
public:
    int numSub(string s) {
        int streak=0;
        int ans=0;
        int mod=1e9+7;
        for(auto ch : s){
            if(ch=='1'){
                streak++;
                ans=(ans+streak)%mod;
            }
            else{
                streak=0;
            }
        }
        return ans;
    }
};