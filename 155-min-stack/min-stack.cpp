class MinStack {
    stack<long> s;
    long min = INT_MAX;
public:
    MinStack() {

        
    }
    
    void push(int val) {
        if(s.empty())
        {
            s.push(val);
            min = val;
        }
        else if(val < min)
        {
            s.push(2L*val-min);
            min = val;
        }
        else {
            s.push(val);
        }
        
    }
    
    void pop() {
        if(s.empty()) return ;
        else if( s.top()>min) s.pop();
        else{
            min = 2L*min-s.top();
            //gives old minimum;
            s.pop();
        }
        
    }
    
    int top() {
        if(s.empty()) return -1;
        else if(s.top()>min) return s.top();
        else return min;
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */