class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int n=s.size();
        unordered_map<char,int>mpp;
        int maxi=-1;
        int ans=-1;
        while(r<n){
            mpp[s[r]]++;
            maxi=max(maxi,mpp[s[r]]);
            if((r-l+1)-maxi > k){
                mpp[s[l]]--;
                l++;
            }
          ans=max(ans,r-l+1);
          r++;
        }
        return ans;
    }
};