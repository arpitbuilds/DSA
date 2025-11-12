class Solution {
public:
    int solve(vector<int>&v){
        int n=v.size();
        vector<int>pse(n);
        vector<int>nse(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && v[st.top()]>=v[i]){
                st.pop();
            }
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
             stack<int>st2;
        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && v[st2.top()]>v[i]){
                st2.pop();
            }
            nse[i]=st2.empty()?n:st2.top();
            st2.push(i);
        }
       int maxi=INT_MIN;
       for(int i=0;i<n;i++){
        int r=nse[i];
        int l=pse[i];
        int w=r-l-1;
        maxi=max(maxi,w*v[i]);
       }
       return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int res=0;
        vector<int>v(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    v[j]+=1;
                }
                else{
                 v[j]=0;
                }
            }
         res=max(res,solve(v));
        }
   
    return res;
    }
};