class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res=0;
        int cnt=0;
        for(auto it : nums){
            if(cnt==0){
                cnt=1;
                res=it;
            }
            else{
                cnt+=res==it?1:-1;
            }
        }
        return res;
    }
};