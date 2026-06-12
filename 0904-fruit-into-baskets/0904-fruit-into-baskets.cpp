class Solution {
public:
    int totalFruit(vector<int>& f) {
        unordered_map<int,int>mpp;
        int n=f.size();
        int l=0;
        int r=0;
        int cnt=0;
        int maxi=0;
        while(r<n){
            mpp[f[r]]++;
            while(mpp.size()>2){
                mpp[f[l]]--;
                if(mpp[f[l]]==0){
                    mpp.erase(f[l]);
                }
                l++;
            }
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};