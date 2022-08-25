//practice.geeksforgeeks.org/problems/sort-a-stack/1

#include <bits/stdc++.h>
using namespace std;

class SortedStack {
public:
	stack<int> s;
	void sort();
};

void insertIntoSortedPosition(stack<int>& s, int val) {
    if (s.size() == 0 || s.top() <= val) {
        s.push(val);
        return;
    }
    
    int temp = s.top();
    s.pop();
    insertIntoSortedPosition(s, val);
    s.push(temp);
}

void SortedStack :: sort() {
   if (s.size() == 1)
    return;
    
    int val = s.top();
    s.pop();
    sort();
    insertIntoSortedPosition(s, val);
}