class MyStack {
public:
    queue<int>q1;
    MyStack() {
        
    }
    
    void push(int x) {
    q1.push(x); 
    int n=q1.size();
    n--;
    while(n--){
    q1.push(q1.front());
    q1.pop();
    } 
    }
    
    int pop() {
    if(empty()){
    return 0;
    } 
    int element=q1.front();
    q1.pop();
    return element;  
    }
    
    int top() {
     if(empty()){
    return 0;
    }  
    return q1.front();  
    }
    
    bool empty() {
    return q1.empty();   
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