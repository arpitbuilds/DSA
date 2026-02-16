// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        sort(bt.begin(),bt.end());
        int n=bt.size();
        int sum=0;
        int tsum=0;
        for(int i=0;i<n;i++){
            tsum+=sum;
            sum+=bt[i];
        }
        return tsum/bt.size();
    }
};