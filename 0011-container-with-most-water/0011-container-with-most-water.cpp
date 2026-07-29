class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int maxi=0;
        while(l<=r){
            int w=r-l;
            int mini=min(height[l],height[r]);
            int area=mini*w;
            maxi=max(maxi,area);
            if(height[l]<height[r]){
                l++;
            }
            else if(height[l]>height[r]){
                r--;
            }
            else{
                l++;
            }
        }
        return maxi;
    }
};