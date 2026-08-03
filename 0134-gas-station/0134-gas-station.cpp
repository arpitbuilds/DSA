class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tgas=0;
        int tcost=0;
        for(auto it : gas){
            tgas+=it;
        }
        for(auto it : cost){
            tcost+=it;
        }
        if(tgas<tcost){
            return -1;
        }
        int cgas=0;
        int sind=0;
        for(int i=0;i<gas.size();i++){
            cgas+=gas[i]-cost[i];
            if(cgas<0){
                cgas=0;
                sind=i+1;
            }
        }
        return sind;
    }
};