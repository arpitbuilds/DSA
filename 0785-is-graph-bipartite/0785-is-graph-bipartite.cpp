class Solution {
public:
    bool solve(int i,vector<vector<int>>&graph,vector<int>&col){
        queue<int>q;
        q.push(i);
        col[i]=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto it : graph[x]){
                if(col[it]==-1){
                    col[it]=!col[x];
                    q.push(it);
                }
                else if(col[it]==col[x]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(solve(i,graph,col)==false){
                    return false;
                }
            }
        }
        return true;
    }
};