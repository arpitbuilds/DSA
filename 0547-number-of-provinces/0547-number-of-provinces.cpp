class Solution {
public:
    void solve(vector<vector<int>>&ls,vector<int>&v,int i){
        v[i]=1;
        for(auto it:ls[i]){
            if(!v[it]){
            solve(ls,v,it);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(n,0);
        vector<vector<int>>ls(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    ls[i].push_back(j);
                    ls[j].push_back(i);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                solve(ls,vis,i);
            }
        }
        return cnt;
    }
};