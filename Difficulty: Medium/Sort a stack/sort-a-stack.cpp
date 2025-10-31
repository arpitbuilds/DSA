class Solution {
  public:
    void insert(stack<int>&st,int x){
        if(st.empty()  || st.top() <= x){
            st.push(x);
            return;
        }
        int t=st.top();
        st.pop();
        insert(st,x);
        st.push(t);
    }
    void sortStack(stack<int> &st) {
        // code here
        if(st.empty()){
            return;
        }
        int top=st.top();
        st.pop();
        sortStack(st);
        insert(st,top);
    }
};
