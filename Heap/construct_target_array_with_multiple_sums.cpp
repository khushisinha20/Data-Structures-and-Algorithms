//leetcode.com/problems/construct-target-array-with-multiple-sums/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> maxHeap;
        long long totalSum = 0;
        
        for (int element: target) {
            totalSum += element;
            maxHeap.push(element);
        }
        
        while (!maxHeap.empty()) {
            int maxElement = maxHeap.top();
            maxHeap.pop();
            
            long long remainingSum = totalSum - maxElement;
            
            if (maxElement == 1 or remainingSum == 1)
                return true;
            
            if (remainingSum == 0 or maxElement < remainingSum)
                return false;
            
            int updatedMaxElement = (int) (maxElement % remainingSum);
            
            if (updatedMaxElement == 0)
                return false;
            
            maxHeap.push(updatedMaxElement);
            totalSum = updatedMaxElement + remainingSum;
        }
        
        return true;
    }
};