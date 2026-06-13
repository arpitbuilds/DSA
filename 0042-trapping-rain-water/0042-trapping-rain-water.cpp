class Solution {
public:
    int trap(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int lmax=0;
        int rmax=0;
        int water=0;
        while(l<=r){
            lmax=max(lmax,height[l]);
            rmax=max(rmax,height[r]);
            if(lmax<=rmax){
                water+=abs(lmax-height[l]);
                l++;
            }
            else{
                water+=abs(rmax-height[r]);
                r--;
            }
        }
        return water;
    }
};