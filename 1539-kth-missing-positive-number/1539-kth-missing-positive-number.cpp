class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int max = arr[n - 1];
        int cnt = 0;
        int j=0;
        for (int i = 1; i <= 2000; i++) {
            if (find(arr.begin(),arr.end(),i)==arr.end()) {
                cnt++;
                if (cnt == k) {
                    return i;
                }
            }
        
        }
        return -1;
    }
};