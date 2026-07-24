class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0;
        int cnt2=0;
        int a=0;
        int b=0;
        int n=nums.size();
        for(auto it : nums){
            if(a==it){
                cnt1++;
            }
            else if(b==it){
                cnt2++;
            }
            else if(cnt1==0){
                cnt1=1;
                a=it;
            }
            else if(cnt2==0){
                cnt2=1;
                b=it;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for(auto it : nums){
            if(it==a){
                cnt1++;
            }
            else if(it==b){
                cnt2++;
            }
        }
        vector<int>ans;
        if(cnt1>n/3){
            ans.push_back(a);
        }
        if(cnt2>n/3 && a!=b){
            ans.push_back(b);
        }
        return ans;
    }
};