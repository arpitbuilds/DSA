class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<m;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    cnt++;
                }
            }
            pq.push({cnt,i});
        }
        while(!pq.empty() && k){
            int x=pq.top().second;
            pq.pop();
            k--;
            ans.push_back(x);
        }
        return ans;
    }
};