//leetcode.com/problems/longest-happy-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> maxHeap;
        
        if (a > 0)
            maxHeap.push({a, 'a'});
        
        if (b > 0)
            maxHeap.push({b, 'b'});
        
        if (c > 0)
            maxHeap.push({c, 'c'});
        
        string res;
        
        while (!maxHeap.empty()) {
            int first = maxHeap.top().first;
            char firstChar = maxHeap.top().second;
            maxHeap.pop();
            
            int n = res.length();
            if (n > 1 and res[n - 1] == res[n - 2] and res[n - 1] == firstChar) {
                if (maxHeap.empty())
                    break;
                
                int second = maxHeap.top().first;
                char secondChar = maxHeap.top().second;
                maxHeap.pop();
                
                res += secondChar;
                --second;
                if (second > 0)
                    maxHeap.push({second, secondChar});
            } else {
                res += firstChar;
                --first;
            }
            
            if (first > 0)
                maxHeap.push({first, firstChar});
        }
        
        return res;
    }
};