//leetcode.com/problems/sort-characters-by-frequency/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void fillFrequencies(unordered_map<char, int>& freq, string s) {
        for (int i = 0; i < s.length(); ++i)
            ++freq[s[i]];
    }
    
    string frequencySort(string s) {
        string res = "";
        unordered_map<char, int> freq;
        fillFrequencies(freq, s);
        priority_queue<pair<int, char>> max_heap;
        for (auto i: freq)
            max_heap.push({i.second, i.first});
        while (!max_heap.empty()) {
            res += string(max_heap.top().first, max_heap.top().second);
            max_heap.pop();
        }
        return res;
    }
};