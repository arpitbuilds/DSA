class Solution {
public:
      int solve(vector<int>& h) {
        stack<int>st;
        stack<int>st2;
        int n=h.size();
        vector<int>pse(n);
        vector<int>nse(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && h[st.top()]>=h[i]){
                st.pop();
            }
            nse[i]=st.empty()?n:st.top();
            st.push(i);

        }
        for(int i=0;i<n;i++){
            while(!st2.empty() && h[st2.top()]>=h[i]){
                st2.pop();
            }
            pse[i]=st2.empty()?-1:st2.top();
            st2.push(i);
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            int left=pse[i];
            int right=nse[i];
            int w=right-left-1;
            maxi=max(maxi,w*h[i]);
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int maxi=0;
        vector<int>v(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    v[j]++;
                }
                else{
                    v[j]=0;
                }
            }
            maxi=max(maxi,solve(v));
        }
        return maxi;
    }
};