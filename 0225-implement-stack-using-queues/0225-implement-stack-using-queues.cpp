class MyStack {
    queue<int> q;
public:
    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int k = q.size()-1;
        while(k>0)
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
            k--;
        }
        k= q.front();
        q.pop();
        return k;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */