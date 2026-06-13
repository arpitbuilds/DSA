class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> fnse(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> fpse(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> pse(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        long long total=0;
        vector<int>pse=fpse(arr);
        vector<int>nse=fnse(arr);
        for(int i=0;i<n;i++){
            long left=nse[i]-i;
            long right=i-pse[i];
            total=((total%mod)+(left%mod)*(right%mod)*(arr[i]%mod))%mod;
        }
        return (int)total;
    }
};