class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int>mpp;
        int ans=INT_MAX;
        for(int i=0;i<cards.size();i++){
            if(mpp.find(cards[i])!=mpp.end()){
                ans=min(ans,i-mpp[cards[i]]+1);
            }
            mpp[cards[i]]=i;
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};