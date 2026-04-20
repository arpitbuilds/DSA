class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
       unordered_map<int,int>mpp;
       int ans=0;
       for(auto it : hours){
         int t=it%24;
         int y=(24-t)%24;
         ans+=mpp[y];
         mpp[t]++;
       } 
       return ans;
    }
};