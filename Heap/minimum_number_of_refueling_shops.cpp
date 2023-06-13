//leetcode.com/problems/minimum-number-of-refueling-stops/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if (target <= startFuel)
            return 0;
        
        int index = 0;
        priority_queue<pair<int, int>> maxHeap;
        
        int currentFuel = startFuel;
        int stops = 0;
        
        while (currentFuel < target) {
            while (index < stations.size() and stations[index][0] <= currentFuel) {
                maxHeap.push({stations[index][1], stations[index][0]});
                ++index;
            }
            
            if (maxHeap.empty())
                return -1;
            
            currentFuel += maxHeap.top().first;
            ++stops;
            maxHeap.pop();
        }
        
        return stops;
    }
};