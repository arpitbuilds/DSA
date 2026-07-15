class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int cntodd=0;
        int cnteven=0;
        int oddstart=1;
        int evenstart=2;
        int sume=0;
        int sumo=0;
        while(cntodd!=n){
            sume+=oddstart;
            oddstart+=2;
            cntodd++;
        }
        while(cnteven!=n){
            sumo+=evenstart;
            evenstart+=2;
            cnteven++;
        }
       return gcd(sume,sumo);
    }
};