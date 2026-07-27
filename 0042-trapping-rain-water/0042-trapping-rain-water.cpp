class Solution {
public:
    int trap(vector<int>& height) {
     int l=0;
     int n=height.size();
     int r=n-1;
     int w=0;
     int maxl=0;
     int maxr=0;
     while(l<r){
        maxl=max(maxl,height[l]);
        maxr=max(maxr,height[r]);
        if(height[l]<height[r]){
            w+=abs(height[l]-maxl);
            l++;
        }
        else{
            w+=abs(height[r]-maxr);
            r--;
        }

     }
     return w;
    }
};