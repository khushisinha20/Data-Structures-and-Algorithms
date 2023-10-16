//leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string result = "";
        int minLength = INT_MAX;
        int start = 0;
        unordered_map<char, int> charFrequency;
        
        for (int end = 0; end < s.length(); ++end) {
            ++charFrequency[s[end]];
            
            while (charFrequency['1'] == k) {
                if (end - start + 1 < minLength) {
                    minLength = end - start + 1;
                    result = s.substr(start, minLength);
                } else if (end - start + 1 == minLength) {
                    string current = s.substr(start, end - start + 1);;
                    if (current.compare(result) < 0) {
                        result = current;
                    }
                }
                
                --charFrequency[s[start]];
                ++start;
            }
        }
        
        return result;
    }
};
