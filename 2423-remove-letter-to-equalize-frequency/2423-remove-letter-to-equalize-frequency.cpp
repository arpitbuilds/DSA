class Solution {
public:
    bool check(unordered_map<char,int>&mpp){
        int freq=0;
        for(auto it : mpp){
            if(it.second==0){
                continue;
            }
            else{
                if(freq==0){
                    freq=it.second;
                }
                else if(freq!=it.second){
                    return false;
                }
            }
        }
        return true;
    }
    bool equalFrequency(string word) {
        unordered_map<char,int>mpp;
        for(auto it : word){
            mpp[it]++;
        }
        int n=word.size();
        for(int i=0;i<n;i++){
            mpp[word[i]]--;
            if(check(mpp)){
                return true;
            }
            mpp[word[i]]++;
        }
        return false;
    }
};