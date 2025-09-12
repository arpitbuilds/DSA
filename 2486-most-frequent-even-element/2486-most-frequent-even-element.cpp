class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int max=0;
        int e=-1;
        unordered_map<int,int>mpp;
        for(auto it:nums){
            if((it%2)==0){
                mpp[it]++;
            }
        }
        for(auto x:mpp){
            if(x.second>max)
            {
                max=x.second;
                e=x.first;
            }
            else if(x.second==max && x.first<e){
                e=x.first;
            }
        }
        return e;
    }
};