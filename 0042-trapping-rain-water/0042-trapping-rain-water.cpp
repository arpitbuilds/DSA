class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int maxl=INT_MIN;
        int maxr=INT_MIN;
        int l=0;
        int r=n-1;
        int water=0;
        while(l<r){
            maxl=max(maxl,height[l]);
            maxr=max(maxr,height[r]);
            if(height[l]>height[r]){
                water=water+abs(maxr-height[r]);
                r--;
            }
            else{
                water=water+abs(maxl-height[l]);
                l++;
            }
        }
        return water;
    }
};