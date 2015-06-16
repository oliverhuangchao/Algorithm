class Stack {
public:
    // Push element x onto stack.
    queue<int> q1;
    queue<int> q2;
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(!q1.empty())
            q1.pop();
    }

    // Get the top element.
    int top() {
        return q1.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty();
    }
};