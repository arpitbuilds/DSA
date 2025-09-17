class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>mpp;
        for(auto s : arr){
            mpp[s]+=1;
        }
        int cnt=0;
        string ans="";
        for(auto x : arr){
            if(mpp[x]==1){
                // ans=x;
                cnt++;
            }
            if(cnt==k){
                return x;
            }
        }
        return "";
    }
};