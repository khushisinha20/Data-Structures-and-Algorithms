//leetcode.com/problems/reduce-array-size-to-the-half/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void storeFrequencies(unordered_map<int, int>& frequency, vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i)
            ++frequency[arr[i]];
    }
    
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> frequency;
        storeFrequencies(frequency, arr);
        vector<pair<int, int>> frequencyMappings;
        for (auto freq: frequency)
            frequencyMappings.push_back({freq.second, freq.first});
        priority_queue<pair<int, int>> maxFrequencyHeap(frequencyMappings.begin(), frequencyMappings.end());
        int integersRemoved = 0;
        int setOfRemovedIntegers = 0;
        while (integersRemoved < arr.size() / 2) {
            integersRemoved += maxFrequencyHeap.top().first;
            ++setOfRemovedIntegers;
            maxFrequencyHeap.pop();
        }
        return setOfRemovedIntegers;
    }
};