//leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int windowSize = cardPoints.size() - k;
        int start = 0;
        int minimumSum = INT_MAX;
        int currentSum = 0;
        int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        
        if (k == cardPoints.size())
            return totalSum;
        
        for (int end = 0; end < cardPoints.size(); ++end) {
            currentSum += cardPoints[end];
            if (end - start + 1 == windowSize) {
                minimumSum = min(currentSum, minimumSum);
                currentSum -= cardPoints[start];
                ++start;
            }
        }
        
        return totalSum - minimumSum;
    }
};