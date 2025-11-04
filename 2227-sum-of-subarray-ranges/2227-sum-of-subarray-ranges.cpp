class Solution {
public:
    vector<int> fnse(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] <= arr[st.top()]) st.pop();
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
            while (!st.empty() && arr[i] < arr[st.top()]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse = fpse(arr);
        vector<int> nse = fnse(arr);
        int total = 0;
        for (int i = 0; i < n; i++) {
            int left = i - pse[i];
            int right = nse[i] - i;
            total += left * right * arr[i];
        }
        return total;
    }

    vector<int> findnge(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n, n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> findpge(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMax(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge = findnge(arr);
        vector<int> pge = findpge(arr);
        int total = 0;
        for (int i = 0; i < n; i++) {
            int left = i - pge[i];
            int right = nge[i] - i;
            total += left * right * arr[i];
        }
        return total;
    }

    int subArrayRanges(vector<int>& nums) {
        return sumSubarrayMax(nums) - sumSubarrayMins(nums);
    }
};
