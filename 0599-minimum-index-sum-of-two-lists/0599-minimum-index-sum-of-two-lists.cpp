class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int mini=INT_MAX;
       unordered_map<string,int>mpp;
        vector<string>ans;
        for(int i=0;i<list1.size();i++){
            mpp[list1[i]]=i;
        }
        for(int j=0;j<list2.size();j++){
            if(mpp.find(list2[j])!=mpp.end()){
                if((j+mpp[list2[j]])<mini){
                    ans.clear();
                    ans.push_back(list2[j]);
                    mini=j+mpp[list2[j]];
                }
                else if((j+mpp[list2[j]])==mini){
                    ans.push_back(list2[j]);
                }
            }
        }
        return ans;
    }
};