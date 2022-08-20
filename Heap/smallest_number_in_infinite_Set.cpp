//leetcode.com/problems/smallest-number-in-infinite-set/

#include <bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    unordered_set<int> st;
    
    SmallestInfiniteSet() {
        int i = 1;
        while (i <= 1000) {
            min_heap.push(i);
            st.insert(i);
            ++i;
        }
    }
    
    int popSmallest() {
        int smallest = min_heap.top();
        min_heap.pop();
        st.erase(smallest);
        return smallest;
    }
    
    void addBack(int num) {
        if (st.find(num) == st.end()) {
            min_heap.push(num);
            st.insert(num);
        }
    }
};