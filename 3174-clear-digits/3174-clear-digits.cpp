class Solution {
public:
    string clearDigits(string s) {
        string stack;
        for(auto it : s){
            if(isdigit(it)){
                if(!stack.empty()){
                    stack.pop_back();
                }
            }
            else{
                stack.push_back(it);
            }
        }
        return stack;
    }
};