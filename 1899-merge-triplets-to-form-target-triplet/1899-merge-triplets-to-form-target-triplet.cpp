class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool xt=false;
        bool yt=false;
        bool zt=false;
        int x=target[0];
        int y=target[1];
        int z=target[2];
        for(auto it : triplets){
            if(it[0]<=x && it[1]<=y && it[2]<=z){
                if(it[0]==x){
                    xt=true;
                }
                if(it[1]==y){
                    yt=true;
                }
                if(it[2]==z){
                    zt=true;
                }
            }
        }
        return xt && yt && zt;
    }
};