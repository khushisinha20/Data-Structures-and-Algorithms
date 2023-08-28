//leetcode.com/problems/check-if-point-is-reachable/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        queue<pair<int, int>> points;
        set<pair<int, int>> visited;
        points.push({targetX, targetY});
        visited.insert({targetX, targetY});
        
        while (!points.empty()) {
            int x = points.front().first;
            int y = points.front().second;
            points.pop();
            
            if (x == 1 or y == 1)
                return true;
            
            pair<int, int> key;
            if (x % 2 == 0) 
                key = {x / 2, y};
            else if (y % 2 == 0) 
                key = {x, y / 2};
            else if (x < y) 
                key = {x, (x + y) / 2};
            else
                key = {(x + y) / 2, y};
            
            if (visited.find(key) == visited.end()) {
                points.push(key);
                visited.insert(key);
            }
        }
        
        return false;
    }
};