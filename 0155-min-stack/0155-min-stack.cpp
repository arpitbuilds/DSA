class MinStack {
public:
    MinStack() {
        
    }
    stack<pair<int,int>>st;
    int mini=INT_MAX;
    void push(int val) {
        if(st.empty()){
            st.push({val,val});
            mini=val;
        }
        else{
        if(val<st.top().second){
            mini=min({mini,val});
            st.push({val,mini});
        }
        else{
            mini=st.top().second;
            st.push({val,mini});

        }
        }

    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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