class Solution {
public:
    int trap(vector<int>& h) {
        int maxl=INT_MIN;
        int maxr=INT_MIN;
        int n=h.size();
        int l=0;
        int r=n-1;
        int w=0;
        while(l<r){
            maxl=max(maxl,h[l]);
            maxr=max(maxr,h[r]);
            if(h[l]<h[r]){
                w+=abs(h[l]-maxl);
                l++;
            }
            else{
                w+=abs(h[r]-maxr);
                r--;
            }
        }
        return w;
    }
};