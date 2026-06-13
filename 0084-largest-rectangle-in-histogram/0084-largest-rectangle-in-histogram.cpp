class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>pse(n);
        vector<int>nse(n);
        stack<int>st;
        stack<int>st1;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
          for(int i=n-1;i>=0;i--){
            while(!st1.empty() && heights[st1.top()]>=heights[i]){
                st1.pop();
            }
            nse[i]=st1.empty()?n:st1.top();
            st1.push(i);
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            int l=pse[i];
            int r=nse[i];
            int w=r-l-1;
            maxi=max(maxi,w*heights[i]);
        }
        return maxi;
    }
};