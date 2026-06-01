class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());
        int paisa=0;
        int n=cost.size();
        for(int i=0;i<n;i++){
            if(i%3!=2){
                paisa+=cost[i];
            }
        }
return paisa;
    }
};