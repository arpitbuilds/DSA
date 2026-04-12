class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int refill=capacity;
        int steps=0;
        for(int i=0;i<plants.size();i++){
            if(capacity<plants[i]){
                steps+=(2*i);
                capacity=refill;
            }
            steps++;
            capacity-=plants[i];
        }
        return steps;
    }
};