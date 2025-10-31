class Solution {
  public:
    void solve(stack<int>&st,int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        int t=st.top();
        st.pop();
        solve(st,x);
        st.push(t);
    }
    void reverseStack(stack<int> &st) {
        // code here
        if(st.empty()){
            return ;
        }
        int top=st.top();
        st.pop();
        reverseStack(st);
        solve(st,top);
    }
};