class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        // int n=nums.size();
        // int cnt=0;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(i!=j && nums[i]+nums[j]==target){
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;
        unordered_map<string,int>mpp;
        for(auto it : nums){
            mpp[it]++;
        }
        int cnt=0;
        for(auto &s : nums){
            if(target.substr(0,s.size())==s){
                string suffix=target.substr(s.size());
                cnt+=mpp[suffix];
                if(suffix==s){
                    cnt--;
                }
            }
        }
        return cnt;
    }
};