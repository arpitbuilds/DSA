class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res=-1;
        int cnt=0;
        for(auto it : nums){
            if(cnt==0){
                res=it;
                cnt++;
            }
            else{
                cnt+=res==it?1:-1;
            }
        }
        return res;
    }
};