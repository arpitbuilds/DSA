class Solution {
public:
     const int MOD = 1e9 + 7;
    vector<int> fnse(vector<int>&arr){
      int n=arr.size();
     stack<int>st;
        vector<int>nse(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int>fpse(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>pse(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                st.pop();
            }
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
       int n=arr.size();
       vector<int>pse=fpse(arr);
       vector<int>nse=fnse(arr);
       long long total =0;
       for(int i=0;i<n;i++){
        long long left=i-pse[i];
        long long right=nse[i]-i;
       total = (total + ((left % MOD) * (right % MOD) % MOD * (arr[i] % MOD)) % MOD) % MOD;

       }
       return (int)total;
    }
};