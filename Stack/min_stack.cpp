//leetcode.com/problems/min-stack/

#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<long long> s;
    long long min_element = LONG_LONG_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if (s.empty()) {
            s.push(val);
            min_element = val;
        } else {
            if (val >= min_element)
                s.push(val);
            else {
                s.push(2LL * val - min_element);
                min_element = val;
            }
        }
    }
    
    void pop() {
        if (s.top() >= min_element)
            s.pop();
        else {
            min_element = 2LL * min_element - s.top();
            s.pop();
        }
    }
    
    int top() {
        if (s.top() >= min_element)
            return s.top();
        else 
            return min_element;
    }
    
    int getMin() {
        return min_element;
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