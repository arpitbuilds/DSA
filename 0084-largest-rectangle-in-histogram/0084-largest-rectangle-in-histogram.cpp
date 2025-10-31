class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxi=INT_MIN;
        int n=heights.size();
        stack<int>st;
        vector<int>pse(n);
        vector<int>nse(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        stack<int>st1;
        for(int i=n-1;i>=0;i--){
            while(!st1.empty() && heights[st1.top()]>heights[i]){
                st1.pop();
            }
            nse[i]=st1.empty()?n:st1.top();
            st1.push(i);
        }
        for(int i=0;i<n;i++){
            int left=nse[i];
            int right=pse[i];
            int width=left-right-1;
            maxi=max(maxi,width*heights[i]);
        }
        return maxi;
    }
};