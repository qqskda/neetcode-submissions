class MinStack {
    stack<pair<int,int>> stk;
public:
    MinStack() {
    }
    
    void push(int val) {
        int currentMin = 0;
        if (!stk.empty())
            currentMin = min(stk.top().second, val);
        else
            currentMin = val;
        stk.push({val, currentMin});
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};
