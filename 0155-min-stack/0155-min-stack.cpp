class MinStack {
public:
    MinStack() {
        
    }
    stack<int>st;
    stack<int>mini;
    void push(int val) {
        if(mini.size()==0){
            mini.push(val);
        }
        else if(val<=mini.top()){
            mini.push(val);
        }
        st.push(val);
    }
    
    void pop() {
        if(mini.top()==st.top()){
            mini.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */