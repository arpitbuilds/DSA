class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& newi) {
        int n=in.size();
        vector<vector<int>>ans;
        int i=0;
        if(in.empty()){
            ans.push_back(newi);
            return ans;
        }
        while(i<n){
            while(i<n && in[i][1]<newi[0]){
                ans.push_back(in[i]);
                i++;
            }
            while(i<n && in[i][0]<=newi[1]){
                newi[0]=min(in[i][0],newi[0]);
                newi[1]=max(in[i][1],newi[1]);
                i++;
            }
            ans.push_back(newi);
            while(i<n){
                ans.push_back(in[i]);
                i++;
            }

        }
        return ans;
    }
};