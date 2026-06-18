class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mpp;
        for(auto x:arr){
            mpp[x]++;
        }
        unordered_set<int>s;
        for(auto x:mpp){
            if(s.count(x.second)){
              return false;
            }
            s.insert(x.second);

        }
        return true;
    }
};