class Solution {
public:
    int trap(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int w=0;
        int lmax=0;
        int rmax=0;
        while(l<r){
            lmax=max(lmax,height[l]);
            rmax=max(rmax,height[r]);
            if(height[l]<height[r]){
                w+=abs(lmax-height[l]);
                l++;
            }
            else{
                w+=abs(rmax-height[r]);
                r--;
            }
        }
        return w;
    }
};