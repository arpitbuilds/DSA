class Solution {
public:
    int maxPower(string s) {
        int streak=1;
        int ans=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                streak++;
            }
            else{
                streak=1;
            }
            ans=max(ans,streak);
        }
        return ans;
    }
};