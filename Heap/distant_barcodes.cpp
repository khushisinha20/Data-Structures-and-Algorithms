//leetcode.com/problems/distant-barcodes/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void storeFrequencies(vector<int>& barcodes, unordered_map<int, int>& frequencies) {
        for (auto barcode: barcodes)
            ++frequencies[barcode];
    }
    
    void storeFrequencyInHeap(unordered_map<int, int>& frequencies, priority_queue<pair<int, int>>& maxHeap) {
        for (auto frequency: frequencies) {
            maxHeap.push({frequency.second, frequency.first});
        }
    }
    
    void rearrange(priority_queue<pair<int, int>>& maxHeap, vector<int>& rearrangedBarcodes) {
        while (maxHeap.size() > 1) {
            int mostFrequent = maxHeap.top().second;
            int highestFrequency = maxHeap.top().first;
            maxHeap.pop();
            int secondMostFrequent = maxHeap.top().second;
            int secondHighestFrequency = maxHeap.top().first;
            maxHeap.pop();
            
            rearrangedBarcodes.push_back(mostFrequent);
            rearrangedBarcodes.push_back(secondMostFrequent);
            --highestFrequency;
            --secondHighestFrequency;
            
            if (highestFrequency > 0)
                maxHeap.push({highestFrequency, mostFrequent});
            if (secondHighestFrequency > 0)
                maxHeap.push({secondHighestFrequency, secondMostFrequent});
        }
        
        if (maxHeap.size() == 1)
            rearrangedBarcodes.push_back(maxHeap.top().second);
    }
    
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> frequencies;
        storeFrequencies(barcodes, frequencies);
        priority_queue<pair<int, int>> maxHeap;
        storeFrequencyInHeap(frequencies, maxHeap);
        vector<int> rearrangedBarcodes;
        rearrange(maxHeap, rearrangedBarcodes);
        return rearrangedBarcodes;
    }
};