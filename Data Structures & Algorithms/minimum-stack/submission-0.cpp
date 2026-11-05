class MinStack {
public:

    stack<int>st; 
    stack<int>mini;
    MinStack() {
        
        
    }
    
    void push(int val) {
        st.push(val);
        if(mini.empty() || mini.top() >= val)
            mini.push(val);
    }
    
    void pop() {

        int val = st.top();
        st.pop(); 
        if(mini.top() == val)
            mini.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini.top();
    }
};
