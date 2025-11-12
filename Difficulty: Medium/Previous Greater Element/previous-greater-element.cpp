class Solution {
  public:
    vector<int> preGreaterEle(vector<int>& arr) {
        //  code here
        int n=arr.size();
        stack<int>st;
        vector<int>nse(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            nse[i]=st.empty()?-1:st.top();
            st.push(arr[i]);
        }
        return nse;
    }
};