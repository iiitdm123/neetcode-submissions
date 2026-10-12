class MinStack {
   public:
    stack<int> st, min_stack;
    MinStack() {}

    void push(int val) {
        st.push(val);
        if(min_stack.empty())
            min_stack.push(val);
        else if (val <= min_stack.top()) {
            min_stack.push(val);
        } else {
            min_stack.push(min_stack.top());
        }
    }

    void pop() {
        st.pop();
        min_stack.pop();
    }

    int top() { return st.top(); }

    int getMin() { return min_stack.top(); }
};
