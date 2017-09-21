class MyQueue {
public:
    /** Initialize your data structure here. */
    std::stack<int> input;
    std::stack<int> output;
    MyQueue() {
        /*
         * Do nothing
         */
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        input.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int element = peek();
        output.pop();
        return element;
    }
    
    /** Get the front element. */
    int peek() {
        int element;
        if(output.empty()) {
            while(!input.empty()) {
                element = input.top();
                input.pop();
                output.push(element);
            }
        }
        return output.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */