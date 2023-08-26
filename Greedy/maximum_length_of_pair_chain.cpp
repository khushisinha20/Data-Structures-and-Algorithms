//leetcode.com/problems/maximum-length-of-pair-chain/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        auto comparator = [&](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        };
        
        sort(pairs.begin(), pairs.end(), comparator);
        int answer = 0;
        int previousRight = INT_MIN;
        
        for (auto& pair: pairs) {
            if (previousRight < pair[0]) {
                ++answer;
                previousRight = pair[1];
            }
        }
        
        return answer;
    }
};