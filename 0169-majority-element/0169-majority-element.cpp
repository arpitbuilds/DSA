class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res=0;
        int cnt=0;
        for(auto it : nums){
            if(cnt==0){
                res=it;
            }
            cnt+=(it==res)?1:-1;
        }
        return res;
    }
};