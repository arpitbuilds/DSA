class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
           vector<vector<int>>v(V);
           for(auto it : edges){
               v[it[0]].push_back(it[1]);
           }
           vector<int>ind(V,0);
           for(int i=0;i<V;i++){
               for(auto it : v[i]){
                   ind[it]++;
               }
           }
           queue<int>q;
           for(int i=0;i<V;i++){
               if(ind[i]==0){
                   q.push(i);
               }
               
           }
           vector<int>ans;
           while(!q.empty()){
               int x=q.front();
               q.pop();
               ans.push_back(x);
               for(auto it : v[x]){
                   ind[it]--;
                   if(ind[it]==0){
                       q.push(it);
                   }
               }
           }
           return ans;
    }
};