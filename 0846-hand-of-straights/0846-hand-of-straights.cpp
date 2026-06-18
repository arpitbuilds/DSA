class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        map<int,int>mpp;
        for(auto it : hand){
            mpp[it]++;
        }
        if(hand.size()%gs!=0){
            return false;
        }
        sort(hand.begin(),hand.end());
        for(int i=0;i<hand.size();i++){
            if(mpp[hand[i]]==0){
                continue;
            }
            for(int j=0;j<gs;j++){
                int cc=hand[i]+j;
                if(mpp[cc]==0){
                    return false;
                }
                 mpp[cc]--;
            }
           
        }
        return true;
    }
};