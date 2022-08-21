//leetcode.com/problems/reorganize-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void fillFrequencies(string& s, unordered_map<char, int>& freq) {
        for (int i = 0; i < s.length(); ++i)
            ++freq[s[i]];
    }
    
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        fillFrequencies(s, freq);
        
        priority_queue<pair<int, char>> max_heap;
        
        for (auto i = freq.begin(); i != freq.end(); ++i)
            max_heap.push({i -> second, i -> first});
        
        string res;
        while (max_heap.size() > 1) {
            pair<int, char> most_frequent = max_heap.top();
            max_heap.pop();
            pair<int, char> second_most_frequent = max_heap.top();
            max_heap.pop();
            
            res += most_frequent.second;
            res += second_most_frequent.second;
            
            --most_frequent.first;
            --second_most_frequent.first;
            
            if (most_frequent.first)
                max_heap.push(most_frequent);
            if (second_most_frequent.first)
                max_heap.push(second_most_frequent);
        }
        
        if (max_heap.size()) {
            if (max_heap.top().first > 1)
                res = "";
            else
                res += max_heap.top().second;
        }
        
        return res;
    }
};