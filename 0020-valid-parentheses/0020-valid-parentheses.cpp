class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(auto it : s){
            if(it=='(' || it=='[' || it=='{'){
                st.push(it);
            }
            else{
                if(st.empty()){
                    return false;
                }
                if((st.top()=='[' && it==']') || (st.top()=='{' && it=='}') || (st.top()=='(' && it==')')){
                    st.pop();
                }
                
                else{
                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};