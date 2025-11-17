class Solution {
  public:
   bool find(int s,vector<vector<int>>&v,vector<int>&vis){
       vis[s]=1;
       queue<pair<int,int>>q;
       q.push({s,-1});
       while(!q.empty()){
           int node=q.front().first;
           int parent=q.front().second;
           q.pop();
           for(auto it : v[node]){
               if(!vis[it]){
                   vis[it]=1;
                   q.push({it,node});
               }
               else if(parent!=it){
                   return  true;
               }
           }
       }
       return false;
   }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>v(V);
        vector<int>vis(V,0);
        for(auto it : edges){
            v[it[0]].push_back(it[1]);
            v[it[1]].push_back(it[0]);
        }
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                if(find(i,v,vis)==true){
                    return true;
                }
            }
        }
        return false;
        
    }
};