class MinStack {
public:
    /** initialize your data structure here. */
    std::stack<int> s;
    std::priority_queue<int> l;

    MinStack() {
        
    }
    
    void push(int x) {

    }
    
    void pop() {
        
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */