class Solution {
public:
    int countHomogenous(string s) {
        int streak=0;
        int mod=1e9+7;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(i==0 || s[i]==s[i-1]){
                streak++;
            }
            else{
                streak=1;
            }
            ans=(ans+streak)%mod;
        }
        return ans;
    }
};