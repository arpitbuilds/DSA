class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int maxi = INT_MIN;
        while (l < r) {
            int w = r - l;
            int area = w * min(height[l], height[r]);
            maxi = max(maxi, area);
            if (height[l] < height[r]) {
                l++;
            } else if (height[l] > height[r]) {
                r--;
            } else {
                l++;
              
            }
        }
        return maxi;
    }
};