class Solution {
public:
    bool canFinish(int c, vector<vector<int>>& p) {
        vector<vector<int>>adj(c);
        for(auto it : p){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>ind(c);
        for(int i=0;i<c;i++){
            for(auto it : adj[i]){
                ind[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<c;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            ans.push_back(x);
            for(auto it : adj[x]){
                ind[it]--;
                if(ind[it]==0){
                    q.push(it);
                }
            }
        }
        return ans.size()==c;
    }
};