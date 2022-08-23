//leetcode.com/problems/find-median-from-data-stream/

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue<double> max_heap;
    priority_queue<double, vector<double>, greater<double>> min_heap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (max_heap.empty() || max_heap.top() > num)
            max_heap.push((double)num);
        else
            min_heap.push((double)num);
        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        } else if (min_heap.size() > max_heap.size() + 1) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if (max_heap.size() > min_heap.size())
            return max_heap.top();
        if (min_heap.size() > max_heap.size())
            return min_heap.top();
        return (min_heap.top() + max_heap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */