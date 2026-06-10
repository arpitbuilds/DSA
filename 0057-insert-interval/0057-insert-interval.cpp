class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& newi) {
        int n=in.size();
        vector<vector<int>>ans;
        int i=0;
        while(i<n){
          if(i<n && newi[0]>in[i][1]){
            ans.push_back(in[i]);
            i++;
          }
          else if(newi[1]<in[i][0]){
            break;
          }
          else{
             newi[0] = min(newi[0], in[i][0]);
             newi[1] = max(newi[1], in[i][1]);
                i++;
          }
        }
         ans.push_back(newi);
         while(i<n){
            ans.push_back(in[i]);
            i++;
         }
        return ans;
    }
};