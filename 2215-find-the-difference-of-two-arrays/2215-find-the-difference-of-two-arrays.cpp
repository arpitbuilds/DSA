class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int>a;
        set<int>b;
        vector<int>av;
        vector<int>bv;
        vector<vector<int>>ans;
        for(auto it : nums1){
            a.insert(it);
        }
        for(auto it : nums2){
            b.insert(it);
        }
        for(auto it : a){
            if(b.find(it)==b.end()){
                av.push_back(it);
            }
        }
        for(auto it : b){
            if(a.find(it)==a.end()){
                bv.push_back(it);
            }
        }
     ans.push_back(av);
     ans.push_back(bv);
     return ans;
    }
};