#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        priority_queue<pair<int, int>> maxHeap;
        for (int i = 0; i < aliceValues.size(); ++i) {
            maxHeap.push({aliceValues[i] + bobValues[i], i});
        }
        
        bool isAliceTurn = true;
        int aliceScore = 0;
        int bobScore = 0;
        
        while (!maxHeap.empty()) {
            int score = maxHeap.top().first;
            int index = maxHeap.top().second;
            maxHeap.pop();
            
            if (isAliceTurn)
                aliceScore += aliceValues[index];
            else
                bobScore += bobValues[index];
            
            isAliceTurn = !isAliceTurn;
        }
        
        if (aliceScore > bobScore)
            return 1;
        if (aliceScore < bobScore)
            return -1;
        return 0;
    }
};