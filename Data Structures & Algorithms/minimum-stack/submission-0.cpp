class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(stMin.empty() || stMin.top() >= val) stMin.push(val);
    }
    
    void pop() {
        if(st.top() == stMin.top()) stMin.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return stMin.top();
    }
private:
    stack<int> st;
    stack<int> stMin;
};
