class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>cnt(3,0);
        int l=0;
        int res=0;
        int n=s.size();
        int r=0;
        while(r<n){
            cnt[s[r]-'a']+=1;
            while(cnt[0]>0 && cnt[1]>0 && cnt[2]>0){
                res+=s.size()-r;
                cnt[s[l]-'a']--;
                l++;

            }
            r++;
        }
        return res;
    }
};