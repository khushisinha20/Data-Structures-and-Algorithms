//leetcode.com/problems/furthest-building-you-can-reach/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> maxHeap;
        int heightDifferences = 0;
        int ans = 0;
        
        for (int i = 1; i < heights.size(); ++i) {
            if (heights[i - 1] >= heights[i]) {
                ans = i;
                continue;
            }
            heightDifferences += heights[i] - heights[i - 1];
            maxHeap.push(heights[i] - heights[i - 1]);
            if (heightDifferences <= bricks)
                ans = i;
            else {
                bool usedLadder = false;
                if (ladders > 0 and heightDifferences > bricks and !maxHeap.empty()) {
                    heightDifferences -= maxHeap.top();
                    maxHeap.pop();
                    --ladders;
                    usedLadder = true;
                } else
                    break;
                if (usedLadder)
                    ans = i;
            }
        }
        
        return ans;
    }
};