class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int res=-1;
        for(auto it : nums){
            if(cnt==0){
                res=it;
            }
            cnt+=res==it?1:-1;
        }
        return res;
    }
};