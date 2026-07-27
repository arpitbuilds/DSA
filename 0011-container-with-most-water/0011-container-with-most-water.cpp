class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int area=0;
        while(l<r){
            int w=r-l;
            int h=min(height[l],height[r]);
            int temp=w*h;
            area=max(area,temp);
            if(height[l]<height[r]){
                l++;
            }
            else if(height[r]<height[l]){
                r--;
            }
            else{
                l++;
            }
        }
        return area;
    }
};