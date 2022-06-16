#include <bits/stdc++.h>
using namespace std;

void insertIntoSortedPos(stack<int>& s, int temp) {
    if (s.size() == 0 || s.top() <= temp) {
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insertIntoSortedPos(s, temp);
    s.push(val);
}

void sortStack(stack<int>& s) {
    if (s.size() == 1)
        return;
    int temp = s.top();
    s.pop();
    sortStack(s);
    insertIntoSortedPos(s, temp);
}

int main() {
    stack<int> s;
    s.push(23);
    s.push(32);
    s.push(24);
    s.push(12);
    s.push(45);
    s.push(10);
    sortStack(s);
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}