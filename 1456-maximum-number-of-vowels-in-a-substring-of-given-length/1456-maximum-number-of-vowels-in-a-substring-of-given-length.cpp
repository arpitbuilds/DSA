class Solution {
public:
     bool vowel(char ch)
    {
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    int maxVowels(string s, int k) {
        int n=s.size();
        int l=0;
        int r=0;
        int cnt=0;
        int ans=INT_MIN;
        while(r<n){
            if(vowel(s[r])){
             cnt++;
            }
            while((r-l+1)>k){
                if(vowel(s[l])){
                    cnt--;
                }
                l++;
            }
            ans=max(ans,cnt);
            r++;
        }
        return ans;
    }
};