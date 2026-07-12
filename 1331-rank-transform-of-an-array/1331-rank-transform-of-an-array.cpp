class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int>mpp;
        vector<int>ans=arr;
        sort(arr.begin(),arr.end());
        int rank=1;
        for(auto it : arr){
            if(mpp.find(it)==mpp.end()){
                mpp[it]=rank;
                rank++;
            }
        }
        
        for(int i=0;i<arr.size();i++){
            ans[i]=mpp[ans[i]];
        }
        return ans;
    }
};