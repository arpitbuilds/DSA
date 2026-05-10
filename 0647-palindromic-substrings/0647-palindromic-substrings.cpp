class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int cnt=0;
        for(int i=0;i<n;i++){
            int left=i-1;
            int right=i+1;
            cnt++;
            while(left>=0 && right<n && s[left]==s[right]){
                left--;
                right++;
                cnt++;
            }
            left=i;
            right=i+1;
            while(left>=0 && right<n && s[left]==s[right]){
                left--;
                right++;
                cnt++;
            }
        }
        return cnt;
    }
};