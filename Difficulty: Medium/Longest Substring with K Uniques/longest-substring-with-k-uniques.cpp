class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        unordered_map<char,int>mpp;
        int l=0;
        int r=0;
        int maxi=-1;
        int n=s.size();
        while(r<n){
            mpp[s[r]]++;
            if(mpp.size()==k){
                maxi=max(maxi,r-l+1);
            }
            while(mpp.size()>k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0){
                    mpp.erase(s[l]);
                }
                l++;
            }
            r++;
        }
        return maxi;
        
    }
};