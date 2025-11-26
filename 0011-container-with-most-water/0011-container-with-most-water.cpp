class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int water=INT_MIN;
        while(l<r){
            int w=r-l;
            int h=min(height[l],height[r]);
            water=max(water,w*h);
            if(height[l]<height[r]){
                l++;
            }
            else if(height[l]>height[r]){
                r--;
            }
            else{
                l++;
                r--;
            }
        }
        return water;
    }
};