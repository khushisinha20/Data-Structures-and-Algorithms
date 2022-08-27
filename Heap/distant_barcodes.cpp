//leetcode.com/problems/distant-barcodes/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void fillFrequencies(vector<int>& barcodes, unordered_map<int, int>& frequency) {
        for (int i = 0; i < barcodes.size(); ++i)
            ++frequency[barcodes[i]];
    }
    
    void fillHeap(unordered_map<int, int>& frequency, priority_queue<pair<int, int>>& max_heap) {
        for (auto freq: frequency)
            max_heap.push({freq.second, freq.first});
    }
    
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int> rearranged_barcode;
        unordered_map<int, int> frequency;
        priority_queue<pair<int, int>> max_heap;
        fillFrequencies(barcodes, frequency);
        fillHeap(frequency, max_heap);
        while (max_heap.size() > 1) {
            auto most_frequent = max_heap.top();
            max_heap.pop();
            auto second_most_frequent = max_heap.top();
            max_heap.pop();
            rearranged_barcode.push_back(most_frequent.second);
            --most_frequent.first;
            rearranged_barcode.push_back(second_most_frequent.second);
            --second_most_frequent.first;
            if (most_frequent.first)
                max_heap.push(most_frequent);
            if (second_most_frequent.first)
                max_heap.push(second_most_frequent);
        }
        if (max_heap.size() == 1)
            rearranged_barcode.push_back(max_heap.top().second);
        return rearranged_barcode;
    }
};