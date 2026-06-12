class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>hash(256,0);
        int l=0;
        int r=0;
        int cnt=0;
        int n=s.size();
        while(r<n){
            hash[s[r]-'a']++;
            while(hash[0]>0 && hash[1]>0 && hash[2]>0){
                cnt+=n-r;
                hash[s[l]-'a']--;
                l++;
            }
             r++;
        }
        return cnt;
    }
};