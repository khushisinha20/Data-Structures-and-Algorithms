//leetcode.com/problems/top-k-frequent-words/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct comparator {
        bool operator() (pair<int, string>& a, pair<int, string>& b) {
            if (a.first != b.first)
                return a.first > b.first;
            return a.second < b.second;
        }
    };
    
    void fillFrequencies(vector<string>& words, unordered_map<string, int>& freq) {
        for (auto word: words)
            ++freq[word];
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        fillFrequencies(words, freq);
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, comparator> min_heap;
        
        for (auto i = freq.begin(); i != freq.end(); ++i) {
            min_heap.push({i -> second, i -> first});
            if (min_heap.size() > k)
                min_heap.pop();
        }
        
        vector<string> res;
        while (!min_heap.empty()) {
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};