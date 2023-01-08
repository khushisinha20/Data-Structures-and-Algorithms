//leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
public:
    priority_queue<double> maxHeap;
    priority_queue<double, vector<double>, greater<double>> minHeap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxHeap.empty() || maxHeap.top() > num)
            maxHeap.push((double)num);
        else
            minHeap.push((double)num);
        
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size())
            return maxHeap.top();
        if (minHeap.size() > maxHeap.size())
            return minHeap.top();
        return (minHeap.top() + maxHeap.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */