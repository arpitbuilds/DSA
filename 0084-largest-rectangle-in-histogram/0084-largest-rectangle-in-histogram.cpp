class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       int n=heights.size();
       vector<int>nse(n);
       vector<int>pse(n);
       stack<int>sn;
       for(int i=n-1;i>=0;i--){
        while(!sn.empty() && heights[sn.top()]>=heights[i]){
            sn.pop();
        }
        nse[i]=sn.empty()?n:sn.top();
        sn.push(i);
       }
       stack<int>sp;
       for(int i=0;i<n;i++){
        while(!sp.empty() && heights[sp.top()]>heights[i]){
             sp.pop();
        }
        pse[i]=sp.empty()?-1:sp.top();
        sp.push(i);
       }
       int maxi=0;
       for(int i=0;i<n;i++){
        int nind=nse[i];
        int pind=pse[i];
        int w=nind-pind-1;
        maxi=max(maxi,w*heights[i]);
       }
       return maxi;
    }
};