#include <bits/stdc++.h>
using namespace std;

void insert(stack<int>& s, int val) {
    if (s.size() == 0) {
        s.push(val);
        return;
    }
    int temp = s.top();
    s.pop();
    insert(s, val);
    s.push(temp);
}

void reverse(stack<int>& s) {
    if (s.size() == 1)
        return;
    int temp = s.top();
    s.pop();
    reverse(s);
    insert(s, temp);
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    reverse(s);
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}