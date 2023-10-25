//leetcode.com/problems/minimum-sum-of-squared-difference/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<long long, int> getFrequencyOfDifferences(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<long long, int> frequencyDifference;
        
        for (int i = 0; i < n; ++i) 
            ++frequencyDifference[abs(nums1[i] - nums2[i])];
        
        return frequencyDifference;
    }
    
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        unordered_map<long long, int> frequencyDifference = getFrequencyOfDifferences(nums1, nums2);
        
        priority_queue<int> maxHeap;
        
        for (auto& pair: frequencyDifference)
            if (pair.first > 0)
                maxHeap.push(pair.first);
        
        int remainingOperations = k1 + k2;
        
        while (!maxHeap.empty() and remainingOperations > 0) {
            auto currentDiff = maxHeap.top();
            maxHeap.pop();
            
            int frequency = frequencyDifference[currentDiff];
            
            long long operations = min(remainingOperations, frequency);
            remainingOperations -= operations;
            
            int updatedFrequency = frequency - operations;
            frequencyDifference[currentDiff] = updatedFrequency; 
            
            if (updatedFrequency > 0) 
                maxHeap.push(currentDiff);
            
            int updatedDifference = currentDiff - 1;
            
            if (updatedDifference > 0) {
                frequencyDifference[updatedDifference] += operations;
                if (frequencyDifference[updatedDifference] == operations)
                    maxHeap.push(updatedDifference);
            }
        }
        
        long long result = 0;
        
        while (!maxHeap.empty()) {
            long long difference = maxHeap.top();
            int frequency = frequencyDifference[difference];
            maxHeap.pop();
            result += (difference * difference * frequency);
        }
        
        return result;
    }
};
