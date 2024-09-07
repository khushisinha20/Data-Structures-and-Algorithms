//leetcode.com/problems/dinner-plate-stacks/

#include <bits/stdc++.h>
using namespace std;

class DinnerPlates {
    int capacity;
    vector<stack<int>> stacks;
    priority_queue<int, vector<int>, greater<int>> pushAvailable;
    set<int> popAvailable;

public:
    DinnerPlates(int capacity) {
        this -> capacity = capacity;
    }

    void push(int val) {
        while (!pushAvailable.empty() and stacks[pushAvailable.top()].size() == capacity)
            pushAvailable.pop();

        if (pushAvailable.empty()) {
            pushAvailable.push(stacks.size());
            stacks.push_back(stack<int>());
        }

        int index = pushAvailable.top();
        stacks[index].push(val);

        if (stacks[index].size() == capacity)
            pushAvailable.pop();

        popAvailable.insert(index);
    }

    int pop() {
        if (popAvailable.empty())
            return -1;

        int index = *popAvailable.rbegin();
        int val = stacks[index].top();
        stacks[index].pop();

        if (stacks[index].empty())
            popAvailable.erase(index);

        pushAvailable.push(index);
        return val;
    }

    int popAtStack(int index) {
        if (index >= stacks.size() or stacks[index].empty())
            return -1;

        int val = stacks[index].top();
        stacks[index].pop();

        if (stacks[index].empty())
            popAvailable.erase(index);

        pushAvailable.push(index);
        return val;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
