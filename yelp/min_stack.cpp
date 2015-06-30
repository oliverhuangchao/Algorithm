#include "basic.h"
class MinStack {
public:
    stack<int> min_z;
    stack<int> z;
    int minvalue;
    MinStack(){
        // do initialization if necessary
        minvalue = INT_MAX;
    }

    void push(int number) {
        // write your code here
        z.push(number);
        minvalue = std::min(minvalue,number);
        min_z.push(minvalue);
    }

    int pop() {
        int value = z.top();
        z.pop();
        min_z.pop();
        if(min_z.empty()) minvalue = INT_MAX;
        else minvalue = min_z.top();
        return value;
        // write your code here
    }

    int min() {
        return min_z.top();
        // write your code here
    }
};
    
int main(){

}
