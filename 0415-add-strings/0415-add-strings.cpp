class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1;
        int j=num2.size()-1;
        int c=0;
        string res="";
        while(i>=0 || j>=0 || c){
            int sum=c;
            if(i>=0){
                sum+=num1[i]-'0';
                i--;
            }
            if(j>=0){
                sum+=num2[j]-'0';
                j--;
            }
            res+=(sum%10)+'0';
            c=sum/10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};