class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
       int l=0;
       int r=n-1;
       int w=0;
       int lmax=INT_MIN;
       int rmax=INT_MIN;
       while(l<=r){
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