//leetcode.com/problems/walking-robot-simulation/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getKey(vector<int> obstacle) {
        char DELIMETER = ',';
        return to_string(obstacle[0]) + DELIMETER + to_string(obstacle[1]);
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        unordered_set<string> obstacleSet;
        for (auto& obstacle: obstacles)
            obstacleSet.insert(getKey(obstacle));

        int x = 0;
        int y = 0;
        int direction = 0;
        int maxDistance = 0;

        for (int& command: commands) {
            if (command == -2) {
                direction = (direction + 3) % 4;
            } else if (command == -1) {
                direction = (direction + 1) % 4;
            } else {
                for (int i = 0; i < command; ++i) {
                    int newX = x + directions[direction][0];
                    int newY = y + directions[direction][1];

                    if (obstacleSet.find(getKey({newX, newY})) == obstacleSet.end()) {
                        x = newX;
                        y = newY;
                        maxDistance = max(maxDistance, x * x + y * y);
                    } else
                        break;
                }
            }
        }

        return maxDistance;
    }
};
