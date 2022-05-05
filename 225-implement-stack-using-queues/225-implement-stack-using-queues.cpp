class MyStack {
public:
    queue<int>q1, q2;
    int t;
    MyStack() {
        
      while(q1.size() != 0)
          q1.pop();
      while(q2.size() != 0)
          q2.pop();
        
    } 
    void push(int x) {
        t = x;
        q1.push(x);
        
    }
    int pop() {
        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q1.pop();
        while(q2.size() != 0){
            q1.push(q2.front());
            t = q2.front();
            q2.pop();
        }
        return x;
    }
    int top() {
        return t;
    }
    
    bool empty() {
        if(q1.size() == 0)
            return true;
        return false;
    }
};