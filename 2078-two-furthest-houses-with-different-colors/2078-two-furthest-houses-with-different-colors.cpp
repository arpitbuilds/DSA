class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int l=0;
        int r=colors.size()-1;
        int ans=INT_MIN;
        int n=colors.size();
        while(l<=r){
            if(colors[l]!=colors[r]){
                ans=max(ans,abs(r-l));
                break;
            }
            l++;
        }
        l=0;
        while(l<=r){
            if(colors[l]!=colors[r]){
                ans=max(ans,abs(r-l));
                break;
            }
            r--;
        }
        return ans;
    }
};