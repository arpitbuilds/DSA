class Solution {
public:
    int minimumTotal(vector<vector<int>>& a) {
        int n=a.size();
        // vector<vector<int>>dp(n,vector<int>(n,0));
        vector<int>front(n,0);
        for(int j=0;j<n;j++){
            front[j]=a[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
          vector<int>cur(n,0);
            for(int j=i;j>=0;j--){
                int d=a[i][j]+front[j];
                int dg=a[i][j]+front[j+1];
                cur[j]=min(d,dg);
            }
            front=cur;
        }
        return front[0];
    }
};