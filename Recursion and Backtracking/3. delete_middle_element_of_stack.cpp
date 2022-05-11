#include <bits/stdc++.h>
using namespace std;

int middleElement(stack<int> s) {
    return (s.size() / 2) + 1;
} 

void deleteMiddleElement(stack<int>& s, int k) {
    if (k == 1) {
        s.pop();
        return;
    }
    int temp = s.top();
    s.pop();
    deleteMiddleElement(s, k - 1);
    s.push(temp);
}

int main() {
    stack<int> s;
    s.push(23);
    s.push(32);
    s.push(24);
    s.push(12);
    s.push(45);
    s.push(10);
    int k = middleElement(s);
    deleteMiddleElement(s, k);
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}